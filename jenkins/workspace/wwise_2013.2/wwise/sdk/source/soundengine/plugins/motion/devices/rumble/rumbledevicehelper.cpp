// File Line: 27
// RVA: 0xACD1D0
void __fastcall RumbleDeviceHelper::InitRumbleController(
        AK::IAkPluginMemAlloc *in_pAllocator,
        char in_iPlayer,
        IDirectInputDevice8W *in_pDevice)
{
  AK::IAkPluginMemAllocVtbl *vfptr; // rax
  AkRumbleControllerDirectInput *v6; // rax
  AkRumbleControllerXInput *v7; // rax

  vfptr = in_pAllocator->vfptr;
  if ( in_pDevice )
  {
    v6 = (AkRumbleControllerDirectInput *)vfptr->Malloc(in_pAllocator, 24ui64);
    if ( v6 )
      AkRumbleControllerDirectInput::AkRumbleControllerDirectInput(v6, in_pDevice);
  }
  else
  {
    v7 = (AkRumbleControllerXInput *)vfptr->Malloc(in_pAllocator, 16ui64);
    if ( v7 )
      AkRumbleControllerXInput::AkRumbleControllerXInput(v7, in_iPlayer);
  }
}

