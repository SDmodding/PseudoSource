// File Line: 61
// RVA: 0x1456750
__int64 Render::_dynamic_initializer_for__gProbeMaterialNameUID__()
{
  UFG::qString::qString(&Render::gProbeMaterialNameUID);
  return atexit((int (__fastcall *)())Render::_dynamic_atexit_destructor_for__gProbeMaterialNameUID__);
}

// File Line: 210
// RVA: 0x1456720
__int64 dynamic_initializer_for__Render::DebugProbes::msProbes__()
{
  return atexit((int (__fastcall *)())dynamic_atexit_destructor_for__Render::DebugProbes::msProbes__);
}

// File Line: 211
// RVA: 0x1456740
hkSeekableStreamReader *dynamic_initializer_for__Render::DebugProbes::msWorldView__()
{
  return Assembly::GetRCX(&Render::DebugProbes::msWorldView);
}

// File Line: 213
// RVA: 0x5EF80
void Render::DebugProbes::Init(void)
{
  UFG::qResourceWarehouse *v0; // rax
  Illusion::StateBlockInventory *Inventory; // rbx
  unsigned int v2; // eax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *StateBlock; // rax

  v0 = UFG::qResourceWarehouse::Instance();
  Inventory = (Illusion::StateBlockInventory *)UFG::qResourceWarehouse::GetInventory(v0, 0x4D04C7F2u);
  if ( !default_paint_uid )
  {
    v2 = UFG::qStringHashUpper32("StateBlock.Default_SceneryLook", 0xFFFFFFFF);
    StateBlock = Illusion::StateBlockInventory::GetStateBlock(Inventory, v2, 1);
    if ( StateBlock )
      default_paint_uid = (unsigned int)StateBlock[1].mNode.mNext;
    else
      default_paint_uid = 0;
  }
}

