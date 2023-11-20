// File Line: 10
// RVA: 0x1519D20
__int64 UFG::_dynamic_initializer_for__gDynamicCoverDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gDynamicCoverDataInventory.vfptr,
    "DynamicCoverDataInventory",
    0xE5150EE3,
    0xE5150CC0,
    0,
    0);
  UFG::gDynamicCoverDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::DynamicCoverDataInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gDynamicCoverDataInventory__);
}

// File Line: 11
// RVA: 0x1519D80
__int64 UFG::_dynamic_initializer_for__gDynamicCoverGroupBundleInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gDynamicCoverGroupBundleInventory.vfptr,
    "DynamicCoverGroupBundleInventory",
    0xEC7A2131,
    0x7117991Bu,
    0,
    0);
  UFG::gDynamicCoverGroupBundleInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::DynamicCoverGroupBundleInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gDynamicCoverGroupBundleInventory__);
}

// File Line: 18
// RVA: 0x454A10
void __fastcall UFG::DynamicCoverDataInventory::Add(UFG::DynamicCoverDataInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rbx
  UFG::DynamicCoverDataInventory *v3; // rdi

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    v2[1].mNode.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v2[1].mNode + 24);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 36
// RVA: 0x454A60
void __fastcall UFG::DynamicCoverGroupBundleInventory::Add(UFG::DynamicCoverGroupBundleInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceData *v2; // rdi
  UFG::DynamicCoverGroupBundleInventory *v3; // rbp
  __int64 v4; // rsi
  UFG::qBaseNodeRB **v5; // rdx
  UFG::qResourceData *v6; // rbx

  v2 = resource_data;
  v3 = this;
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    v2[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)((char *)&v2[1].mNode + 16);
    v4 = 0i64;
    if ( LODWORD(v2[1].mNode.mParent) )
    {
      do
      {
        v5 = &v2[1].mNode.mChild[0]->mParent + v4;
        if ( *v5 )
          v6 = (UFG::qResourceData *)((char *)v5 + (_QWORD)*v5);
        else
          v6 = 0i64;
        if ( v6 )
        {
          UFG::qResourceData::qResourceData(v6);
          v6[1].mNode.mChild[1] = (UFG::qBaseNodeRB *)((char *)&v6[1].mNode + 24);
        }
        UFG::qResourceInventory::Add((UFG::qResourceInventory *)&UFG::gDynamicCoverDataInventory.vfptr, v6);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < LODWORD(v2[1].mNode.mParent) );
    }
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 43
// RVA: 0x4730B0
void __fastcall UFG::DynamicCoverGroupBundleInventory::Remove(UFG::DynamicCoverGroupBundleInventory *this, UFG::qResourceData *resource_data)
{
  UFG::DynamicCoverGroupBundle *v2; // rbx

  v2 = (UFG::DynamicCoverGroupBundle *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::DynamicCoverGroupBundle::~DynamicCoverGroupBundle(v2);
}

