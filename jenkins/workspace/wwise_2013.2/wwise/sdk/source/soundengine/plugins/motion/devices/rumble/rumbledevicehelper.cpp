// File Line: 27
// RVA: 0xACD1D0
void __fastcall RumbleDeviceHelper::InitRumbleController(AK::IAkPluginMemAlloc *in_pAllocator, char in_iPlayer, void *in_pDevice)
{
  AK::IAkPluginMemAllocVtbl *v3; // rax
  IDirectInputDevice8W *v4; // rbx
  char v5; // di
  AkRumbleControllerDirectInput *v6; // rax
  AkRumbleControllerXInput *v7; // rax

  v3 = in_pAllocator->vfptr;
  v4 = (IDirectInputDevice8W *)in_pDevice;
  v5 = in_iPlayer;
  if ( in_pDevice )
  {
    v6 = (AkRumbleControllerDirectInput *)v3->Malloc(in_pAllocator, 24ui64);
    if ( v6 )
      AkRumbleControllerDirectInput::AkRumbleControllerDirectInput(v6, v4);
  }
  else
  {
    v7 = (AkRumbleControllerXInput *)v3->Malloc(in_pAllocator, 16ui64);
    if ( v7 )
      AkRumbleControllerXInput::AkRumbleControllerXInput(v7, v5);
  }
}

