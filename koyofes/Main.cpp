#include <Siv3D.hpp>
#include <cmath>

void Main() {
	// FontSetting
	const Font font(30);

	// WindowSetting
	Window::SetTitle(L"KoyoFes.2018");
	const Size targetSize(1920, 1080);
	Window::SetStyle(WindowStyle::Sizeable);

	// MovieSetting
	bool play_flag = experimental::MediaPlayer::Open(L"Movie/movie.mp4");
	bool is_playing = false;

	// ImageSetting
	const Image logo(L"Image/logo.png");
	const Texture logo_texture(logo);
	Webcam webcam;
	bool cam_flag = webcam.open(0, Size(640, 480)) && webcam.start();
	DynamicTexture cam_texture;

	/*
	for (const auto& camera : WebcamManager::Enumerate()) {
		// デバイス ID とカメラの名前を表示
		Println(camera.deviceID, L": ", camera.name);
	}
	WaitKey();
	*/

	while (System::Update()) {
		// WindowControl
		if (Input::KeyF.clicked){
			if (!Window::SetFullscreen(true, targetSize)){
				System::Exit();
			}
		}
		if (Input::KeyW.clicked){
			if (!Window::SetFullscreen(false, targetSize)){
				System::Exit();
			}
		}

		// MovieControl
		if (play_flag) {
			if (std::abs(experimental::MediaPlayer::GetLengthSec() - experimental::MediaPlayer::GetPosSec()) > 0.5) {
				if (Input::KeySpace.clicked) {
					if (experimental::MediaPlayer::IsPlaying() && is_playing) {
						is_playing = false;
						experimental::MediaPlayer::Pause();
					} else {
						is_playing = true;
						experimental::MediaPlayer::Play();
					}
				} else {
					logo_texture.draw();
				}
			} else {
				is_playing = false;
				play_flag = false;
			}
		} else {
			/*
			logo_texture.draw();
			if (Input::KeySpace.clicked) {
				is_playing = false;
				play_flag = true;
			}
			*/
			if (cam_flag) {
				if (webcam.hasNewFrame()) {
					webcam.getFrame(cam_texture);
				}
				if (cam_texture) {
					cam_texture.resize(Window::Width(), Window::Height()).draw();
				}
			}
		}
	}
}