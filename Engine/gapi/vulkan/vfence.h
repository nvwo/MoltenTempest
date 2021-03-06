#pragma once

#include <Tempest/AbstractGraphicsApi>
#include "vulkan_sdk.h"

namespace Tempest {
namespace Detail {

class VDevice;

class VFence : public AbstractGraphicsApi::Fence {
  public:
    VFence(VDevice& dev);
    ~VFence() override;

    void wait() override;
    bool wait(uint64_t time) override;
    void reset() override;

    VkFence impl=VK_NULL_HANDLE;

  private:
    VkDevice device=nullptr;
  };

}}
