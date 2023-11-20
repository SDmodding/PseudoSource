// File Line: 89
// RVA: 0x14E4EB0
UFG::qMemoryPool *dynamic_initializer_for__gCrtMemPool__()
{
  UFG::qMemoryPool *result; // rax

  result = UFG::gMainMemoryPool;
  gCrtMemPool = UFG::gMainMemoryPool;
  return result;
}

// File Line: 93
// RVA: 0x3FC690
void DebugTestInit(void)
{
  gDebugTestEnable = 0;
}

