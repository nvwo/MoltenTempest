#pragma once

#include <Tempest/AbstractGraphicsApi>
#include <Tempest/UniformsLayout>

#include "../utility/dptr.h"

namespace Tempest {

class Device;
class CommandBuffer;
class UniformsLayout;
template<class T>
class Encoder;

class RenderPipeline final {
  public:
    RenderPipeline()=default;
    RenderPipeline(RenderPipeline&& f)=default;
    ~RenderPipeline() = default;
    RenderPipeline& operator = (RenderPipeline&& other);

    bool isEmpty() const { return impl.handler==nullptr; }
    const UniformsLayout& layout() const { return ulay; }

  private:
    RenderPipeline(Detail::DSharedPtr<AbstractGraphicsApi::Pipeline*>&&    p,
                   Detail::DSharedPtr<AbstractGraphicsApi::UniformsLay*>&& lay);

    UniformsLayout                                     ulay;
    Detail::DSharedPtr<AbstractGraphicsApi::Pipeline*> impl;

  friend class Tempest::Device;
  friend class Tempest::CommandBuffer;
  friend class Tempest::Encoder<Tempest::CommandBuffer>;

  template<class T>
  friend class Tempest::Detail::ResourcePtr;
  };

}
