// File Line: 21
// RVA: 0xACCFB0
void __fastcall AkCreateRumblePlugin(AK::IAkPluginMemAlloc *in_pAllocator)
{
  RumbleMixBus *v1; // rax

  v1 = (RumbleMixBus *)in_pAllocator->vfptr->Malloc(in_pAllocator, 192i64);
  if ( v1 )
    RumbleMixBus::RumbleMixBus(v1);
}

