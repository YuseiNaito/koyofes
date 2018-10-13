#include <Siv3D.hpp>
#include <chrono>
#include <cmath>

using namespace std::chrono_literals;

void Main() {
  // FontSetting
  const Font font(30);

  // WindowSetting
  Window::SetTitle(L"KoyoFes.2018");
  const Size targetSize(1920, 1080);
  Window::SetStyle(WindowStyle::Sizeable);
  Window::SetFullscreen(true, targetSize);
  Cursor::SetStyle(CursorStyle::None);

  // MovieSetting
  bool play_flag{experimental::MediaPlayer::Open(L"Movie/logo.mp4")};
  bool is_playing{false};
  auto end_tp{std::chrono::high_resolution_clock::now()};
  auto now{std::chrono::high_resolution_clock::now()};
  auto before{now};
  auto tmp{now};
  auto ctp_tp{now};
  auto start_time{6s};

  // Mode setting
  bool rest{false};
  bool move{true};

  // ImageSetting
  const Image logo(L"Image/logo.png");
  const Image wait(L"Image/wait.png");
  const Image ui1_1(L"Image/UI1-1.png");
  const Image ui1_2(L"Image/UI1-2.png");
  const Image ui1_3(L"Image/UI1-3.png");
  const Image ui1_4(L"Image/UI1-4.png");
  const Image ui1_5(L"Image/UI1-5.png");
  const Image ui1_6(L"Image/UI1-6.png");
  const Image ui1_7(L"Image/UI1-7.png");
  const Image ui1_8(L"Image/UI1-8.png");
  const Image ui1_9(L"Image/UI1-9.png");
  const Image ui1_10(L"Image/UI1-10.png");
  const Image ui1_11(L"Image/UI1-11.png");
  const Image ui1_12(L"Image/UI1-12.png");
  const Image ui1_13(L"Image/UI1-13.png");
  const Image ui1_14(L"Image/UI1-14.png");
  const Image ui1_15(L"Image/UI1-15.png");
  const Image ui1_16(L"Image/UI1-16.png");
  const Image ui1_17(L"Image/UI1-17.png");
  const Image ui1_18(L"Image/UI1-18.png");
  const Image ui1_19(L"Image/UI1-19.png");
  const Image ui1_20(L"Image/UI1-20.png");
  const Image ui2(L"Image/UI2.png");
  const Image ui3(L"Image/UI3.png");
  const Image ui4(L"Image/UI4.png");
  const Image ui5(L"Image/UI5.png");

  const Texture logo_texture(logo);
  const Texture wait_texture(wait);
  const Texture ui1_1_texture(ui1_1);
  const Texture ui1_2_texture(ui1_2);
  const Texture ui1_3_texture(ui1_3);
  const Texture ui1_4_texture(ui1_4);
  const Texture ui1_5_texture(ui1_5);
  const Texture ui1_6_texture(ui1_6);
  const Texture ui1_7_texture(ui1_7);
  const Texture ui1_8_texture(ui1_8);
  const Texture ui1_9_texture(ui1_9);
  const Texture ui1_10_texture(ui1_10);
  const Texture ui1_11_texture(ui1_11);
  const Texture ui1_12_texture(ui1_12);
  const Texture ui1_13_texture(ui1_13);
  const Texture ui1_14_texture(ui1_14);
  const Texture ui1_15_texture(ui1_15);
  const Texture ui1_16_texture(ui1_16);
  const Texture ui1_17_texture(ui1_17);
  const Texture ui1_18_texture(ui1_18);
  const Texture ui1_19_texture(ui1_19);
  const Texture ui1_20_texture(ui1_20);
  const Texture ui2_texture(ui2);
  const Texture ui3_texture(ui3);
  const Texture ui4_texture(ui4);
  const Texture ui5_texture(ui5);

  double ui_rad[3] = {0};
  auto ui_rad1sign{1};
  Webcam webcam;
  bool cam_flag{webcam.open(1, Size(640, 480)) && webcam.start()};
  DynamicTexture cam_texture;

  /*
  for (const auto& camera : WebcamManager::Enumerate()) {
          // デバイス ID とカメラの名前を表示
          Println(camera.deviceID, L": ", camera.name);
  }
  WaitKey();
  */

  while (System::Update()) {
    now = std::chrono::high_resolution_clock::now();
    before = tmp;
    tmp = now;
    if (Input::KeySpace.clicked) end_tp = now;

    // WindowControl
    if (Input::KeyF.clicked) {
      if (!Window::SetFullscreen(true, targetSize)) {
        Cursor::SetStyle(CursorStyle::None);
        System::Exit();
      }
    }
    if (Input::KeyW.clicked) {
      if (!Window::SetFullscreen(false, targetSize)) {
        Cursor::SetStyle(CursorStyle::Default);
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
          wait_texture.resize(Window::Width(), Window::Height()).draw();
        }
      } else {
        rest = false;
        move = true;
        is_playing = false;
        play_flag = false;
        end_tp = std::chrono::high_resolution_clock::now();
        ctp_tp = end_tp;
      }
    } else {
      if (cam_flag && now - end_tp > start_time) {
        if (webcam.hasNewFrame()) {
          webcam.getFrame(cam_texture);
        }
        if (cam_texture) {
          cam_texture.resize(Window::Width(), Window::Height()).draw();
        }
      } else {
        Rect(0, 0, Window::Width(), Window::Height()).draw(Color(0, 0, 0));
      }

      if (rest) {
        wait_texture.resize(Window::Width(), Window::Height()).draw();
        if (Input::KeyR.clicked) {
          rest = false;
          move = true;
        }
      }

      // HUD描画
      else if (move) {
        if (Input::KeyR.clicked) {
          rest = true;
          move = false;
          play_flag = true;
        }
        // Catpult1
        if (now - end_tp < start_time) {
          if (now - end_tp > 0s)
            ui1_12_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 0.2s)
            ui1_13_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 0.4s)
            ui1_14_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 0.6s)
            ui1_15_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 0.8s)
            ui1_16_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 1.0s)
            ui1_17_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 1.2s)
            ui1_18_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 1.4s)
            ui1_19_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 1.6s)
            ui1_20_texture.resize(Window::Width(), Window::Height()).draw();
        }

        // Catpult2
        if (now - end_tp < 4.8s) {
          if (0.15s > now - ctp_tp)
            ui1_9_texture.resize(Window::Width(), Window::Height()).draw();
          if (0.3s > now - ctp_tp && now - ctp_tp > 0.15s)
            ui1_10_texture.resize(Window::Width(), Window::Height()).draw();
          if (0.45s > now - ctp_tp && now - ctp_tp > 0.3s)
            ui1_11_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - ctp_tp > 0.7s) ctp_tp = now;
        }

        // Base
        if (now - end_tp > 1s)
          ui1_1_texture.resize(Window::Width(), Window::Height()).draw();
        if (now - end_tp > 1.2s)
          ui1_2_texture.resize(Window::Width(), Window::Height()).draw();
        if (now - end_tp > 1.4s)
          ui1_3_texture.resize(Window::Width(), Window::Height()).draw();
        if (6s > now - end_tp && now - end_tp > 0s)
          // ui1_4_texture.resize(Window::Width(), Window::Height()).draw();
          if (now - end_tp > 1.6s)
            ui1_5_texture.resize(Window::Width(), Window::Height()).draw();
        if (now - end_tp > 1.8s)
          ui1_6_texture.resize(Window::Width(), Window::Height()).draw();
        if (now - end_tp > 2.0s)
          ui1_7_texture.resize(Window::Width(), Window::Height()).draw();
        if (now - end_tp > 3.5s)
          ui1_8_texture.resize(Window::Width(), Window::Height()).draw();

        // dynamic HUD
        if (now - end_tp > 3.1s)
          ui2_texture
              .resize(Window::Width() * ui2.width / ui1_1_texture.width,
                      Window::Height() * ui2.height / ui1_1_texture.height)
              .rotate(-ui_rad[0])
              .draw((Window::Width() -
                     Window::Width() * ui2.width / ui1_1_texture.width) /
                        2,
                    (Window::Height() -
                     Window::Height() * ui2.height / ui1_1_texture.height) /
                        2);
        if (now - end_tp > 2.5s)
          ui3_texture
              .resize(Window::Width() * ui3.width / ui1_1_texture.width,
                      Window::Height() * ui3.height / ui1_1_texture.height)
              .rotate(ui_rad[0])
              .draw((Window::Width() -
                     Window::Width() * ui3.width / ui1_1_texture.width) /
                        2,
                    (Window::Height() -
                     Window::Height() * ui3.height / ui1_1_texture.height) /
                        2);
        if (now - end_tp > 2.7s)
          ui4_texture
              .resize(Window::Width() * ui4.width / ui1_1_texture.width,
                      Window::Height() * ui4.height / ui1_1_texture.height)
              .rotate(ui_rad[1])
              .draw((Window::Width() -
                     Window::Width() * ui4.width / ui1_1_texture.width) /
                        2,
                    (Window::Height() -
                     Window::Height() * ui4.height / ui1_1_texture.height) /
                        2);
        if (now - end_tp > 2.7s)
          ui4_texture
              .resize(Window::Width() * ui4.width / ui1_1_texture.width,
                      Window::Height() * ui4.height / ui1_1_texture.height)
              .rotate(-ui_rad[1])
              .draw((Window::Width() -
                     Window::Width() * ui4.width / ui1_1_texture.width) /
                        2,
                    (Window::Height() -
                     Window::Height() * ui4.height / ui1_1_texture.height) /
                        2);
        if (now - end_tp > 2.9s)
          ui5_texture
              .resize(Window::Width() * ui5.width / ui1_1_texture.width,
                      Window::Height() * ui5.height / ui1_1_texture.height)
              .rotate(ui_rad[2])
              .draw((Window::Width() -
                     Window::Width() * ui5.width / ui1_1_texture.width) /
                        2,
                    (Window::Height() -
                     Window::Height() * ui5.height / ui1_1_texture.height) /
                        2);

        // calc omega
        std::chrono::duration<double> sec = now - before;
        ui_rad[0] =
            ui_rad[0] < TwoPi ? ui_rad[0] + Radians(45) * sec.count() : 0;
        ui_rad[1] = ui_rad[1] < TwoPi
                        ? ui_rad[1] + ui_rad1sign * Radians(25) * sec.count()
                        : 0;
        ui_rad[2] =
            ui_rad[2] < TwoPi ? ui_rad[2] + Radians(30) * sec.count() : 0;
      }
    }
  }
}