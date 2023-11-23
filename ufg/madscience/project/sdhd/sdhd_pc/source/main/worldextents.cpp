// File Line: 27
// RVA: 0x4273C0
UFG::qVector2 *__fastcall UFG::GetWorldExtents_min()
{
  UFG::BSPInventory *Inventory; // rax
  UFG::qResourceInventoryVtbl *vfptr; // rdi
  UFG::BSPInventory *v2; // rbx
  unsigned int v3; // eax
  UFG::BSP *v4; // rax

  if ( !gWorldExtentsInitialized )
  {
    Inventory = UFG::BSP::getInventory();
    vfptr = Inventory->vfptr;
    v2 = Inventory;
    v3 = UFG::qStringHash32("World", 0xFFFFFFFF);
    v4 = (UFG::BSP *)vfptr->Get(v2, v3);
    UFG::BSP::GetAABB2D(v4, &UFG::gWorldExtents_min, &UFG::gWorldExtents_max);
    gWorldExtentsInitialized = 1;
  }
  return &UFG::gWorldExtents_min;
}

// File Line: 38
// RVA: 0x427340
UFG::qVector2 *__fastcall UFG::GetWorldExtents_max()
{
  UFG::BSPInventory *Inventory; // rax
  UFG::qResourceInventoryVtbl *vfptr; // rdi
  UFG::BSPInventory *v2; // rbx
  unsigned int v3; // eax
  UFG::BSP *v4; // rax

  if ( !gWorldExtentsInitialized )
  {
    Inventory = UFG::BSP::getInventory();
    vfptr = Inventory->vfptr;
    v2 = Inventory;
    v3 = UFG::qStringHash32("World", 0xFFFFFFFF);
    v4 = (UFG::BSP *)vfptr->Get(v2, v3);
    UFG::BSP::GetAABB2D(v4, &UFG::gWorldExtents_min, &UFG::gWorldExtents_max);
    gWorldExtentsInitialized = 1;
  }
  return &UFG::gWorldExtents_max;
}

