// File Line: 56
// RVA: 0x1458310
__int64 Illusion::_dynamic_initializer_for__gVertexDeclInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&Illusion::gVertexDeclInventory.vfptr,
    "VertexDeclInventory",
    0x3E5FDA3Eu,
    0xF7FC6B2D,
    0,
    0);
  Illusion::gVertexDeclInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::VertexDeclInventory::`vftable;
  return atexit(Illusion::_dynamic_atexit_destructor_for__gVertexDeclInventory__);
}

// File Line: 65
// RVA: 0x8DE70
void __fastcall Illusion::VertexDeclInventory::Add(Illusion::VertexDeclInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  Illusion::VertexDeclInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  Illusion::IVertexDeclPlat::OnLoad((Illusion::IVertexDeclPlat *)v2);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 76
// RVA: 0x949D0
void __fastcall Illusion::VertexDeclInventory::Remove(Illusion::VertexDeclInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx

  v2 = resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  Illusion::IVertexDeclPlat::OnUnload((Illusion::IVertexDeclPlat *)v2);
}

