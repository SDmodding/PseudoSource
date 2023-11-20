// File Line: 40
// RVA: 0x12CAA04
_BOOL8 __fastcall heap_init()
{
  crtheap = GetProcessHeap();
  return crtheap != 0i64;
}

