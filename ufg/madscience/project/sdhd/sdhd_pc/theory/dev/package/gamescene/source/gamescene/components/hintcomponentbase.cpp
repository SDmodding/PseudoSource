// File Line: 36
// RVA: 0x23E230
const char *__fastcall UFG::HintComponentBase::GetTypeName(UFG::HintComponentBase *this)
{
  return "HintComponentBase";
}

// File Line: 39
// RVA: 0x1470BD0
__int64 dynamic_initializer_for__UFG::HintComponentBase::mspDefaultFont__()
{
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&UFG::HintComponentBase::mspDefaultFont.mPrev);
  return atexit(dynamic_atexit_destructor_for__UFG::HintComponentBase::mspDefaultFont__);
}

// File Line: 62
// RVA: 0x23E530
void UFG::HintComponentBase::Init(void)
{
  unsigned int v0; // ebx
  UFG::qResourceInventory *v1; // rax
  UFG::qResourceWarehouse *v2; // rax

  v0 = UFG::qStringHash32("LucidaConsole", 0xFFFFFFFF);
  v1 = `UFG::qGetResourceInventory<Render::Font>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>'::`2'::result )
  {
    v2 = UFG::qResourceWarehouse::Instance();
    v1 = UFG::qResourceWarehouse::GetInventory(v2, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>'::`2'::result = v1;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&UFG::HintComponentBase::mspDefaultFont.mPrev, 0x69FCCB4Cu, v0, v1);
}

