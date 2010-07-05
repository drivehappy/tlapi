
//
// Rerouting code developed by dengus

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <stdio.h>

#include "tlapi.h"

#include "Test.h"


//const char*dll = "winmm.dll";
//const char*dll = "C:\\win32\\system32\\winmm";
const char*dll = "C:\\windows\\system32\\winmm";
HMODULE dll_hm = LoadLibrary(dll);

const char*__str__s_ln = "%s\n";
const char*__str__failed = "failed";

extern "C" {
  //if (!__func__##x) __func__##x=win::GetProcAddress(win::GetModuleHandle(dll),#x); \

#define bounce(x)\
  void* __func__##x = 0; \
  const char*__str__##x = #x; \
  void __declspec(dllexport) __declspec(naked) x() { \
  /*_asm push __str__##x*/  \
  /*_asm push __str__s_ln*/ \
  /*_asm call ds:printf*/ \
  /*_asm add esp, 8*/ \
  _asm cmp __func__##x, 0 \
  _asm jnz l1 \
  _asm push __str__##x  \
  _asm push dll_hm \
  _asm call ds:GetProcAddress \
  _asm test eax, eax \
  _asm jz fail \
  _asm mov __func__##x, eax \
  _asm l1: \
  _asm mov eax, __func__##x \
  _asm jmp eax \
  _asm fail: \
  _asm push 0 \
  _asm push __str__failed \
  _asm push __str__##x \
  _asm push 0 \
  _asm call ds:MessageBox \
}


  bounce(aux32Message);
  bounce(auxGetDevCapsA);
  bounce(auxGetDevCapsW);
  bounce(auxGetNumDevs);
  bounce(auxGetVolume);
  bounce(auxOutMessage);
  bounce(auxSetVolume);
  bounce(CloseDriver);
  bounce(DefDriverProc);
  bounce(DriverCallback);
  bounce(DrvGetModuleHandle);
  bounce(GetDriverModuleHandle);
  bounce(gfxAddGfx);
  bounce(gfxBatchChange);
  bounce(gfxCreateGfxFactoriesList);
  bounce(gfxCreateZoneFactoriesList);
  bounce(gfxLevelDestroyMonsterDeviceInterfaceList);
  bounce(gfxEnumerateGfxs);
  //bounce(_gfxLogoff@0);
  //bounce(_gfxLogon@4);
  bounce(gfxModifyGfx);
  bounce(gfxOpenGfx);
  bounce(gfxRemoveGfx);
  bounce(joy32Message);
  bounce(joyConfigChanged);
  bounce(joyGetDevCapsA);
  bounce(joyGetDevCapsW);
  bounce(joyGetNumDevs);
  bounce(joyGetPos);
  bounce(joyGetPosEx);
  bounce(joyGetThreshold);
  bounce(joyReleaseCapture);
  bounce(joySetCapture);
  bounce(joySetThreshold);
  bounce(mci32Message);
  bounce(mciDriverNotify);
  bounce(mciDriverYield);
  bounce(mciExecute);
  bounce(mciFreeCommandResource);
  bounce(mciGetCreatorTask);
  bounce(mciGetDeviceIDA);
  bounce(mciGetDeviceIDFromElementIDA);
  bounce(mciGetDeviceIDFromElementIDW);
  bounce(mciGetDeviceIDW);
  bounce(mciGetDriverData);
  bounce(mciGetErrorStringA);
  bounce(mciGetErrorStringW);
  bounce(mciGetYieldProc);
  bounce(mciLoadCommandResource);
  bounce(mciSendCommandA);
  bounce(mciSendCommandW);
  bounce(mciSendStringA);
  bounce(mciSendStringW);
  bounce(mciSetDriverData);
  bounce(mciSetYieldProc);
  bounce(mid32Message);
  bounce(midiConnect);
  bounce(midiDisconnect);
  bounce(midiInAddBuffer);
  bounce(midiInClose);
  bounce(midiInGetDevCapsA);
  bounce(midiInGetDevCapsW);
  bounce(midiInGetErrorTextA);
  bounce(midiInGetErrorTextW);
  bounce(midiInGetID);
  bounce(midiInGetNumDevs);
  bounce(midiInMessage);
  bounce(midiInOpen);
  bounce(midiInPrepareHeader);
  bounce(midiInReset);
  bounce(midiInStart);
  bounce(midiInStop);
  bounce(midiInUnprepareHeader);
  bounce(midiOutCacheDrumPatches);
  bounce(midiOutCachePatches);
  bounce(midiOutClose);
  bounce(midiOutGetDevCapsA);
  bounce(midiOutGetDevCapsW);
  bounce(midiOutGetErrorTextA);
  bounce(midiOutGetErrorTextW);
  bounce(midiOutGetID);
  bounce(midiOutGetNumDevs);
  bounce(midiOutGetVolume);
  bounce(midiOutLongMsg);
  bounce(midiOutMessage);
  bounce(midiOutOpen);
  bounce(midiOutPrepareHeader);
  bounce(midiOutReset);
  bounce(midiOutSetVolume);
  bounce(midiOutShortMsg);
  bounce(midiOutUnprepareHeader);
  bounce(midiStreamClose);
  bounce(midiStreamOpen);
  bounce(midiStreamOut);
  bounce(midiStreamPause);
  bounce(midiStreamPosition);
  bounce(midiStreamProperty);
  bounce(midiStreamRestart);
  bounce(midiStreamStop);
  bounce(MigrateAllDrivers);
  bounce(MigrateSoundEvents);
  bounce(mixerClose);
  bounce(mixerGetControlDetailsA);
  bounce(mixerGetControlDetailsW);
  bounce(mixerGetDevCapsA);
  bounce(mixerGetDevCapsW);
  bounce(mixerGetID);
  bounce(mixerGetLineControlsA);
  bounce(mixerGetLineControlsW);
  bounce(mixerGetLineInfoA);
  bounce(mixerGetLineInfoW);
  bounce(mixerGetNumDevs);
  bounce(mixerMessage);
  bounce(mixerOpen);
  bounce(mixerSetControlDetails);
  bounce(mmDrvInstall);
  bounce(mmGetCurrentTask);
  bounce(mmioAdvance);
  bounce(mmioAscend);
  bounce(mmioClose);
  bounce(mmioCreateChunk);
  bounce(mmioDescend);
  bounce(mmioFlush);
  bounce(mmioGetInfo);
  bounce(mmioInstallIOProcA);
  bounce(mmioInstallIOProcW);
  bounce(mmioOpenA);
  bounce(mmioOpenW);
  bounce(mmioRead);
  bounce(mmioRenameA);
  bounce(mmioRenameW);
  bounce(mmioSeek);
  bounce(mmioSendMessage);
  bounce(mmioSetBuffer);
  bounce(mmioSetInfo);
  bounce(mmioStringToFOURCCA);
  bounce(mmioStringToFOURCCW);
  bounce(mmioWrite);
  bounce(mmsystemGetVersion);
  bounce(mmTaskBlock);
  bounce(mmTaskCreate);
  bounce(mmTaskSignal);
  bounce(mmTaskYield);
  bounce(mod32Message);
  bounce(mxd32Message);
  bounce(NotifyCallbackData);
  bounce(OpenDriver);
  //bounce(PlaySound);
  bounce(PlaySoundA);
  bounce(PlaySoundW);
  bounce(SendDriverMessage);
  bounce(sndPlaySoundA);
  bounce(sndPlaySoundW);
  bounce(tid32Message);
  bounce(timeBeginPeriod);
  bounce(timeEndPeriod);
  bounce(timeGetDevCaps);
  bounce(timeGetSystemTime);
  bounce(timeGetTime);
  bounce(timeKillEvent);
  bounce(timeSetEvent);
  bounce(waveInAddBuffer);
  bounce(waveInClose);
  bounce(waveInGetDevCapsA);
  bounce(waveInGetDevCapsW);
  bounce(waveInGetErrorTextA);
  bounce(waveInGetErrorTextW);
  bounce(waveInGetID);
  bounce(waveInGetNumDevs);
  bounce(waveInGenericModelGetPosition);
  bounce(waveInMessage);
  bounce(waveInOpen);
  bounce(waveInPrepareHeader);
  bounce(waveInReset);
  bounce(waveInStart);
  bounce(waveInStop);
  bounce(waveInUnprepareHeader);
  bounce(waveOutBreakLoop);
  bounce(waveOutClose);
  bounce(waveOutGetDevCapsA);
  bounce(waveOutGetDevCapsW);
  bounce(waveOutGetErrorTextA);
  bounce(waveOutGetErrorTextW);
  bounce(waveOutGetID);
  bounce(waveOutGetNumDevs);
  bounce(waveOutGetPitch);
  bounce(waveOutGetPlaybackRate);
  bounce(waveOutGenericModelGetPosition);
  bounce(waveOutGetVolume);
  bounce(waveOutMessage);
  bounce(waveOutOpen);
  bounce(waveOutPause);
  bounce(waveOutPrepareHeader);
  bounce(waveOutReset);
  bounce(waveOutRestart);
  bounce(waveOutSetPitch);
  bounce(waveOutSetPlaybackRate);
  bounce(waveOutSetVolume);
  bounce(waveOutUnprepareHeader);
  bounce(waveOutWrite);
  bounce(wid32Message);
  bounce(winmmDbgOut);
  bounce(WinmmLogoff);
  bounce(WinmmLogon);
  bounce(winmmSetDebugLevel);
  bounce(wod32Message);
  bounce(WOW32DriverCallback);
  bounce(WOW32ResolveMultiMediaHandle);
  bounce(WOWAppExit);

}


uintptr_t _beginthreadex( 
             void *security,
             unsigned stack_size,
             unsigned ( __stdcall *start_address )( void * ),
             void *arglist,
             unsigned initflag,
             unsigned *thrdaddr 
             ) {
               return 0;
}

void init();
void deinit();

int cnt=0;
bool initialized = false;

HANDLE this_module;

BOOL WINAPI DllMain(HANDLE hModule, DWORD dwReason, void *lpReserved)
{
  dll_hm = LoadLibrary(dll);
  this_module = hModule;
  AllocConsole();
  freopen("CONOUT$", "w", stdout);

  if (GetModuleHandle("torchlight.exe")) {
    if (dwReason == DLL_PROCESS_ATTACH) {
      log("Torchlight Multiplayer");
      log("Base is at %p", GetModuleHandle("torchlight.exe"));

      TLAPI::Initialize();

      TestSetup();

      log("Done.");
    } else if (dwReason==DLL_THREAD_ATTACH) {
    } else if (dwReason==DLL_PROCESS_DETACH) {
    }
  }

  return TRUE;
}
