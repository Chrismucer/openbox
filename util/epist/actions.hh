// -*- mode: C++; indent-tabs-mode: nil; c-basic-offset: 2; -*-
// actions.hh for Epistrophy - a key handler for NETWM/EWMH window managers.
// Copyright (c) 2002 - 2002 Ben Jansens <ben at orodu.net>
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#ifndef __actions_hh
#define __actions_hh

extern "C" {
#include <X11/Xlib.h>
}

#include <list>
#include <string>

class Action {
public:
  enum ActionType {
    noaction = 0,
    execute, //done
    iconify, //done
    raise, //done
    lower, //done
    close, //done
    toggleShade, //done
    toggleOmnipresent, //done
    moveWindowUp, //done
    moveWindowDown, //done
    moveWindowLeft, //done
    moveWindowRight, //done
    resizeWindowWidth, //done
    resizeWindowHeight, //done

    toggleMaximizeFull, //done
    toggleMaximizeVertical, //done
    toggleMaximizeHorizontal, //done

    sendToWorkspace, //done
    sendToNextWorkspace,
    sendToPrevWorkspace,

    nextWindow, //done for now
    prevWindow, //done for now
    nextWindowOnAllWorkspaces, //done for now
    prevWindowOnAllWorkspaces, //done for now

    nextWindowOnAllScreens, //done for now
    prevWindowOnAllScreens, //done for now

    nextWindowOfClass, //done for now
    prevWindowOfClass, //done for now
    nextWindowOfClassOnAllWorkspaces, //done for now
    prevWindowOfClassOnAllWorkspaces, //done for now

    upWindow,
    downWindow,
    leftWindow,
    rightWindow,

    changeWorkspace, //done
    nextWorkspace, //done
    prevWorkspace, //done

    upWorkspace, //all done
    downWorkspace,
    leftWorkspace,
    rightWorkspace,

    nextScreen, //done for now
    prevScreen, //done for now
  
    // these are openbox extensions
    showRootMenu,
    showWorkspaceMenu,
    toggleDecorations,

    toggleGrabs,
    stringChain, 
    keyChain,
    numberChain,

    cancelChain, //done

    NUM_ACTIONS
  };

private:
  enum ActionType _type;
  const KeyCode _keycode;
  const unsigned int _modifierMask;

  int _numberParam;
  std::string _stringParam;
public:
  inline enum ActionType type() const { return _type;}
  inline const KeyCode keycode() const { return _keycode; }
  inline const unsigned int modifierMask() const { return _modifierMask; }
  inline const int number() const { return _numberParam; }
  inline const std::string &string() const { return _stringParam; }

  Action(enum ActionType type, KeyCode keycode, unsigned int modifierMask,
         const std::string &str = "");
};
  
typedef std::list<Action> ActionList;

#endif
