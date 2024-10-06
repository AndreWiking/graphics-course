#pragma once

#include <etna/Window.hpp>
#include <etna/PerFrameCmdMgr.hpp>
#include <etna/ComputePipeline.hpp>
#include <etna/Image.hpp>
#include <etna/Sampler.hpp>
#include <chrono>

#include "wsi/OsWindowingManager.hpp"


class App
{
public:
  App();
  ~App();


  void run();

private:
  void drawFrame();

private:
  OsWindowingManager windowing;
  std::unique_ptr<OsWindow> osWindow;

  glm::uvec2 resolution;
  bool useVsync;

  std::unique_ptr<etna::Window> vkWindow;
  std::unique_ptr<etna::PerFrameCmdMgr> commandManager;

  etna::ComputePipeline pipeline;
  etna::Image imageCopy;
  etna::Sampler defaultSampler;

  struct
  {
    uint32_t screen_size_x;
    uint32_t screen_size_y;
    float mouse_pos_x;
    float mouse_pos_y;
    float time;
  } paramShared;

  std::chrono::time_point<std::chrono::system_clock> start_time = std::chrono::system_clock::now();
};
