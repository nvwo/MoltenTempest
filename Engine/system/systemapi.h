#pragma once

#include <Tempest/Platform>
#include <Tempest/Rect>
#include <cstdint>

namespace Tempest {

class MouseEvent;
class KeyEvent;
class Widget;
class Application;
class Window;

class SystemApi {
  public:
    struct Window;

    enum ShowMode : uint8_t {
      Minimized,
      Normal,
      Maximized,
      FullScreen
      };

    virtual ~SystemApi()=default;
    static Window*  createWindow(Tempest::Window* owner, uint32_t width, uint32_t height);
    static Window*  createWindow(Tempest::Window* owner, ShowMode sm);
    static void     destroyWindow(Window* w);
    static void     exit();

    static uint32_t width (Window* w);
    static uint32_t height(Window* w);
    static Rect     windowClientRect(SystemApi::Window *w);

    static bool     setAsFullscreen(SystemApi::Window *w, bool fullScreen);
    static bool     isFullscreen(SystemApi::Window *w);

    static void     setCursorPosition(int x, int y);
    static void     showCursor(bool show);

  protected:
    struct AppCallBack {
      virtual ~AppCallBack()=default;
      virtual uint32_t onTimer()=0;
      };

    SystemApi();
    virtual Window*  implCreateWindow (Tempest::Window *owner,uint32_t width,uint32_t height) = 0;
    virtual Window*  implCreateWindow (Tempest::Window *owner,ShowMode sm) = 0;
    virtual void     implDestroyWindow(Window* w) = 0;
    virtual void     implExit() = 0;

    virtual uint32_t implWidth (Window* w) = 0;
    virtual uint32_t implHeight(Window* w) = 0;
    virtual Rect     implWindowClientRect(SystemApi::Window *w) = 0;

    virtual bool     implSetAsFullscreen(SystemApi::Window *w, bool fullScreen) = 0;
    virtual bool     implIsFullscreen(SystemApi::Window *w) = 0;

    virtual void     implSetCursorPosition(int x, int y) = 0;
    virtual void     implShowCursor(bool show) = 0;

    virtual int      implExec(AppCallBack& cb) = 0;

    static void      dispatchRender    (Tempest::Window& cb);
    static void      dispatchMouseDown (Tempest::Window& cb,MouseEvent& e);
    static void      dispatchMouseUp   (Tempest::Window& cb,MouseEvent& e);
    static void      dispatchMouseMove (Tempest::Window& cb,MouseEvent& e);
    static void      dispatchMouseWheel(Tempest::Window& cb,MouseEvent& e);

    static void      dispatchKeyDown   (Tempest::Window& cb, Tempest::KeyEvent& e, uint32_t scancode);
    static void      dispatchKeyUp     (Tempest::Window& cb, Tempest::KeyEvent& e, uint32_t scancode);

  private:
    static int        exec(AppCallBack& cb);
    static SystemApi& inst();

  friend class Application;
  };

}
