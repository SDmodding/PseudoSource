// File Line: 56
// RVA: 0x1458310
__int64 Illusion::_dynamic_initializer_for__gVertexDeclInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &Illusion::gVertexDeclInventory,
    "VertexDeclInventory",
    0x3E5FDA3Eu,
    0xF7FC6B2D,
    0,
    0);
  Illusion::gVertexDeclInventory.vfptr = (UFG::qResourceInventoryVtbl *)&Illusion::VertexDeclInventory::`vftable;
  return atexit((int (__fastcall *)())Illusion::_dynamic_atexit_destructor_for__gVertexDeclInventory__);
}

// File Line: 65
// RVA: 0x8DE70
void __fastcall Illusion::VertexDeclInventory::Add(
        Illusion::VertexDeclInventory *this,
        UFG::qResourceData *resource_data)
{
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  Illusion::IVertexDeclPlat::OnLoad((Illusion::IVertexDeclPlat *)resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 76
// RVA: 0x949D0
void __fastcall Illusion::VertexDeclInventory::Remove(
        Illusion::VertexDeclInventory *this,
        UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  Illusion::IVertexDeclPlat::OnUnload((Illusion::IVertexDeclPlat *)resource_data);
}

