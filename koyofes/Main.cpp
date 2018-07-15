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
	bool play_flag = false; // experimental::MediaPlayer::Open(L"Movie/movie.mp4");
	bool is_playing = false;

	// ImageSetting
	const Image logo(L"Image/logo.png");
	const Image ui1(L"Image/UI1.png");
	const Image ui2(L"Image/UI2.png");
	const Image ui3(L"Image/UI3.png");
	const Image ui4(L"Image/UI4.png");

	const Texture logo_texture(logo);
	const Texture ui1_texture(ui1);
	const Texture ui2_texture(ui2);
	const Texture ui3_texture(ui3);
	const Texture ui4_texture(ui4);

	double ui_rad[2] = {0};
	Webcam webcam;
	bool cam_flag = webcam.open(1, Size(640, 480)) && webcam.start();
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
					logo_texture.resize(Window::Width(), Window::Height()).draw();
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

			// UI描画
			{
				ui1_texture.resize(Window::Width(), Window::Height()).draw();
				ui2_texture.rotate(ui_rad[0]).draw((Window::Width() - ui2.width) / 2, (Window::Height() - ui2.height) / 2);
				// ui2_texture.rotate(-ui_rad[0]).draw((Window::Width() - ui2.width) / 2, (Window::Height() - ui2.height) / 2);
				ui3_texture.rotate(ui_rad[1]).draw((Window::Width() - ui3.width) / 2, (Window::Height() - ui3.height) / 2);
				ui4_texture.rotate(-ui_rad[1]).draw((Window::Width() - ui4.width) / 2, (Window::Height() - ui4.height) / 2);
				ui_rad[0] = ui_rad[0] < TwoPi ? ui_rad[0] + Radians(0.5) : 0;
				ui_rad[1] = ui_rad[1] < TwoPi ? ui_rad[1] + Radians(0.25) : 0;
			}
		}
	}
}