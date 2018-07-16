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
  bool play_flag =
      false;  // experimental::MediaPlayer::Open(L"Movie/movie.mp4");
  bool is_playing = false;

  // ImageSetting
  const Image logo(L"Image/logo.png");
  const Image ui1(L"Image/UI1.png");
  const Image ui2(L"Image/UI2.png");
  const Image ui3(L"Image/UI3.png");
  const Image ui4(L"Image/UI4.png");
  const Image ui5(L"Image/UI5.png");

  const Texture logo_texture(logo);
  const Texture ui1_texture(ui1);
  const Texture ui2_texture(ui2);
  const Texture ui3_texture(ui3);
  const Texture ui4_texture(ui4);
  const Texture ui5_texture(ui5);

  double ui_rad[3] = {0};
  auto ui_rad1sign = 1;
  Webcam webcam;
  bool cam_flag = webcam.open(1, Size(640, 480)) && webcam.start();
  DynamicTexture cam_texture;

  TextureRegion textures[] = {
      ui1_texture.resize(Window::Width(), Window::Height())
          .resize(Window::Width() * ui2.width / ui1_texture.width,
                  Window::Height() * ui2.height / ui1_texture.height),
      ui2_texture.resize(Window::Width() * ui2.width / ui1_texture.width,
                         Window::Height() * ui2.height / ui1_texture.height),
      ui3_texture.resize(Window::Width() * ui3.width / ui1_texture.width,
                         Window::Height() * ui3.height / ui1_texture.height),
      ui4_texture.resize(Window::Width() * ui4.width / ui1_texture.width,
                         Window::Height() * ui4.height / ui1_texture.height),
      ui4_texture.resize(Window::Width() * ui4.width / ui1_texture.width,
                         Window::Height() * ui4.height / ui1_texture.height),
      ui5_texture.resize(Window::Width() * ui5.width / ui1_texture.width,
                         Window::Height() * ui5.height / ui1_texture.height)};

  /*
  for (const auto& camera : WebcamManager::Enumerate()) {
          // デバイス ID とカメラの名前を表示
          Println(camera.deviceID, L": ", camera.name);
  }
  WaitKey();
  */

  while (System::Update()) {
    // WindowControl
    if (Input::KeyF.clicked) {
      if (!Window::SetFullscreen(true, targetSize)) {
        System::Exit();
      }
    }
    if (Input::KeyW.clicked) {
      if (!Window::SetFullscreen(false, targetSize)) {
        System::Exit();
      }
    }

    // MovieControl
    if (play_flag) {
      if (std::abs(experimental::MediaPlayer::GetLengthSec() -
                   experimental::MediaPlayer::GetPosSec()) > 0.5) {
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
      } else {
        Rect(0, 0, Window::Width(), Window::Height()).draw(Color(0, 0, 0));
      }
      // HUD描画
      {
        textures[0].draw();
        textures[1]
            .rotate(-ui_rad[0])
            .draw((Window::Width() -
                   Window::Width() * ui2.width / ui1_texture.width) /
                      2,
                  (Window::Height() -
                   Window::Height() * ui2.height / ui1_texture.height) /
                      2);
        textures[1].rotate(ui_rad[0]).draw(
            (Window::Width() -
             Window::Width() * ui3.width / ui1_texture.width) /
                2,
            (Window::Height() -
             Window::Height() * ui3.height / ui1_texture.height) /
                2);
        textures[2].rotate(ui_rad[1]).draw(
            (Window::Width() -
             Window::Width() * ui4.width / ui1_texture.width) /
                2,
            (Window::Height() -
             Window::Height() * ui4.height / ui1_texture.height) /
                2);
        textures[3]
            .rotate(-ui_rad[1])
            .draw((Window::Width() -
                   Window::Width() * ui4.width / ui1_texture.width) /
                      2,
                  (Window::Height() -
                   Window::Height() * ui4.height / ui1_texture.height) /
                      2);
        textures[4].rotate(ui_rad[2]).draw(
            (Window::Width() -
             Window::Width() * ui5.width / ui1_texture.width) /
                2,
            (Window::Height() -
             Window::Height() * ui5.height / ui1_texture.height) /
                2);

        ui_rad[0] = ui_rad[0] < TwoPi ? ui_rad[0] + Radians(0.5) : 0;
        ui_rad[1] =
            ui_rad[1] < TwoPi ? ui_rad[1] + ui_rad1sign * Radians(0.25) : 0;
        ui_rad[2] = ui_rad[2] < TwoPi ? ui_rad[2] + Radians(0.1) : 0;
        // if ((ui_rad1sign == 1 && ui_rad[1] > HalfPi + QuarterPi / 4.0) ||
        // (ui_rad1sign == -1 && ui_rad[1] < HalfPi - QuarterPi / 4.0))
        // ui_rad1sign *= -1;
      }
    }
  }
}