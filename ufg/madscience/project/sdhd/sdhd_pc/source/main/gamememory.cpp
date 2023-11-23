// File Line: 17
// RVA: 0x426F70
void __fastcall UFG::qUserCallback_InitMainPool(UFG *this)
{
  UFG::gMainPoolMemoryPlat = UFG::qSystemAlloc(0x1F400000ui64);
  UFG::qMemoryPool::Init(
    UFG::gMainMemoryPool,
    "Main Pool",
    (char *)UFG::gMainPoolMemoryPlat,
    0x1F400000i64,
    0x4000000,
    1,
    1u,
    0i64,
    1,
    1);
}

