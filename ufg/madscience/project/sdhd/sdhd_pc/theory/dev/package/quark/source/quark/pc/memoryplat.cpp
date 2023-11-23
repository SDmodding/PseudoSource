// File Line: 83
// RVA: 0xA3A4D0
LPVOID __fastcall UFG::qSystemAlloc(SIZE_T size)
{
  return VirtualAlloc(0i64, size, 0x103000u, 4u);
}

// File Line: 89
// RVA: 0xA3A4F0
void __fastcall UFG::qSystemFree(void *memory)
{
  VirtualFree(memory, 0i64, 0x8000u);
}

// File Line: 120
// RVA: 0xA3A500
LPVOID __fastcall UFG::qVirtualAlloc(SIZE_T size)
{
  return VirtualAlloc(0i64, size, 0x2000u, 1u);
}

// File Line: 135
// RVA: 0xA3A520
LPVOID __fastcall UFG::qVirtualCommit(void *memory, SIZE_T size, UFG::qVirtualAccess access)
{
  DWORD v4; // r9d

  if ( access == qVirtualAccess_ReadOnly )
    return VirtualAlloc(memory, size, 0x1000u, 2u);
  v4 = 1;
  if ( access == qVirtualAccess_ReadWrite )
    v4 = 4;
  return VirtualAlloc(memory, size, 0x1000u, v4);
}

// File Line: 144
// RVA: 0xA3A560
void __fastcall UFG::qVirtualDecommit(void *memory, SIZE_T size)
{
  VirtualFree(memory, size, 0x4000u);
}

// File Line: 154
// RVA: 0xA3A570
__int64 __fastcall UFG::qVirtualQuery(const void *memory, UFG::qBasicMemInfo *out)
{
  unsigned __int8 Protect; // cl
  unsigned __int8 AllocationProtect; // dl
  int v5; // eax
  UFG::qVirtualState v6; // eax
  int v7; // eax
  _MEMORY_BASIC_INFORMATION Buffer; // [rsp+20h] [rbp-38h] BYREF

  if ( (unsigned int)VirtualQuery(memory, &Buffer, 0x30ui64) != 48 )
    return 0i64;
  Protect = Buffer.Protect;
  if ( out )
  {
    AllocationProtect = Buffer.AllocationProtect;
    out->mpBaseAddress = Buffer.BaseAddress;
    out->mpAllocationBase = Buffer.AllocationBase;
    if ( (AllocationProtect & 2) != 0 )
      v5 = 1;
    else
      v5 = (AllocationProtect >> 1) & 2;
    out->mVirtualAccessAtAllocation = v5;
    out->mRegionSize = Buffer.RegionSize;
    if ( (Buffer.State & 0x1000) != 0 )
      v6 = qVirtualMemState_Commit;
    else
      v6 = ((Buffer.State & 0x10000) == 0) + 1;
    out->mVirtualStateCurrent = v6;
    if ( (Protect & 2) != 0 )
      v7 = 1;
    else
      v7 = (Protect >> 1) & 2;
    out->mVirtualAccessCurrent = v7;
    out->mVirtualRegionType = 0;
  }
  if ( (Protect & 4) != 0 )
    return 2i64;
  return (Protect & 2) != 0;
}

