#pragma once

/*
  This defines several "Event" macros to help setup callback functionality within
  Torchlight classes.

  EVENT_DECL sets up:
    1. Two private static vectors that hold pre and post function callbacks when
       the Event fires.
    2. A public type for the Event function, including argument definitions.
    3. Public RegisterEvent_EVENTNAME that will add callback functions.
    4. Public FireEvent_EVENTNAME for pre and post that calls the saved callback functions.
       Note: These are only public because Hook() requires them to be, users should NOT 
             call these.
    Note: Used within the Torchlight class definitions.

  EVENT_DEF sets up:
    1. The two static definitions of the vectors, used in a "global" cpp for linking correctly.
    Note: Used in Events.cpp solely.

  EVENT_INIT sets up:
    1. Easy Hook() calling
    Note: Used in tlapi.cpp solely for the initial function hooking.
**/

#define EVENT_DECL(className,retType,name,args,stdargs) \
public: \
  typedef retType(__cdecl *EventType_##name)args; \
private: \
  static vector<EventType_##name> m_Callback_##name##_pre; \
  static vector<EventType_##name> m_Callback_##name##_post; \
public: \
  static void RegisterEvent_##name(EventType_##name funcPre, EventType_##name funcPost) { \
    if(funcPre) \
      m_Callback_##name##_pre.push_back(funcPre); \
    if(funcPost) \
      m_Callback_##name##_post.push_back(funcPost); \
  }; \
  static void FireEvent_##name##_Pre STDARG { \
    vector<EventType_##name>::iterator itr = m_Callback_##name##_pre.begin(); \
    for (; itr != m_Callback_##name##_pre.end(); itr++) { \
      (*itr)stdargs; \
    } \
  }; \
  static void FireEvent_##name##_Post STDARG { \
    vector<EventType_##name>::iterator itr = m_Callback_##name##_post.begin(); \
    for (; itr != m_Callback_##name##_post.end(); itr++) { \
      (*itr)stdargs; \
    } \
  };

#define EVENT_DEF(className,retType,name,args) \
  vector<className::EventType_##name> className::m_Callback_##name##_pre; \
  vector<className::EventType_##name> className::m_Callback_##name##_post;

#define EVENT_INIT(className,name,argCount) \
  Hook(name, &className::FireEvent_##name##_Pre, &className::FireEvent_##name##_Post, HOOK_THISCALL, argCount);
