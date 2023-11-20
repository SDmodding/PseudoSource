// File Line: 27
// RVA: 0x4273C0
UFG::qVector2 *__fastcall UFG::GetWorldExtents_min()
{
  UFG::BSPInventory *v0; // rax
  UFG::qResourceInventoryVtbl *v1; // rdi
  UFG::BSPInventory *v2; // rbx
  unsigned int v3; // eax
  UFG::BSP *v4; // rax

  if ( !gWorldExtentsInitialized )
  {
    v0 = UFG::BSP::getInventory();
    v1 = v0->vfptr;
    v2 = v0;
    v3 = UFG::qStringHash32("World", 0xFFFFFFFF);
    v4 = (UFG::BSP *)v1->Get((UFG::qResourceInventory *)&v2->vfptr, v3);
    UFG::BSP::GetAABB2D(v4, &UFG::gWorldExtents_min, &UFG::gWorldExtents_max);
    gWorldExtentsInitialized = 1;
  }
  return &UFG::gWorldExtents_min;
}

// File Line: 38
// RVA: 0x427340
UFG::qVector2 *__fastcall UFG::GetWorldExtents_max()
{
  UFG::BSPInventory *v0; // rax
  UFG::qResourceInventoryVtbl *v1; // rdi
  UFG::BSPInventory *v2; // rbx
  unsigned int v3; // eax
  UFG::BSP *v4; // rax

  if ( !gWorldExtentsInitialized )
  {
    v0 = UFG::BSP::getInventory();
    v1 = v0->vfptr;
    v2 = v0;
    v3 = UFG::qStringHash32("World", 0xFFFFFFFF);
    v4 = (UFG::BSP *)v1->Get((UFG::qResourceInventory *)&v2->vfptr, v3);
    UFG::BSP::GetAABB2D(v4, &UFG::gWorldExtents_min, &UFG::gWorldExtents_max);
    gWorldExtentsInitialized = 1;
  }
  return &UFG::gWorldExtents_max;
}

