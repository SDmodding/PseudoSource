// File Line: 10
// RVA: 0x1519D20
__int64 UFG::_dynamic_initializer_for__gDynamicCoverDataInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gDynamicCoverDataInventory,
    "DynamicCoverDataInventory",
    0xE5150EE3,
    0xE5150CC0,
    0,
    0);
  UFG::gDynamicCoverDataInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::DynamicCoverDataInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gDynamicCoverDataInventory__);
}

// File Line: 11
// RVA: 0x1519D80
__int64 UFG::_dynamic_initializer_for__gDynamicCoverGroupBundleInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gDynamicCoverGroupBundleInventory,
    "DynamicCoverGroupBundleInventory",
    0xEC7A2131,
    0x7117991Bu,
    0,
    0);
  UFG::gDynamicCoverGroupBundleInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::DynamicCoverGroupBundleInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gDynamicCoverGroupBundleInventory__);
}

// File Line: 18
// RVA: 0x454A10
void __fastcall UFG::DynamicCoverDataInventory::Add(
        UFG::DynamicCoverDataInventory *this,
        UFG::qResourceData *resource_data)
{
  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    resource_data[1].mNode.mChild[1] = (UFG::qBaseNodeRB *)&resource_data[1].mNode.mUID;
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 36
// RVA: 0x454A60
void __fastcall UFG::DynamicCoverGroupBundleInventory::Add(
        UFG::DynamicCoverGroupBundleInventory *this,
        UFG::qResourceData *resource_data)
{
  __int64 i; // rsi
  UFG::qBaseNodeRB **v5; // rdx
  UFG::qResourceData *v6; // rbx

  if ( resource_data )
  {
    UFG::qResourceData::qResourceData(resource_data);
    resource_data[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)&resource_data[1].mNode.mChild[1];
    for ( i = 0i64; (unsigned int)i < LODWORD(resource_data[1].mNode.mParent); i = (unsigned int)(i + 1) )
    {
      v5 = &resource_data[1].mNode.mChild[0]->mParent + i;
      if ( *v5 )
        v6 = (UFG::qResourceData *)((char *)v5 + (_QWORD)*v5);
      else
        v6 = 0i64;
      if ( v6 )
      {
        UFG::qResourceData::qResourceData(v6);
        v6[1].mNode.mChild[1] = (UFG::qBaseNodeRB *)&v6[1].mNode.mUID;
      }
      UFG::qResourceInventory::Add(&UFG::gDynamicCoverDataInventory, v6);
    }
  }
  UFG::qResourceInventory::Add(this, resource_data);
}

// File Line: 43
// RVA: 0x4730B0
void __fastcall UFG::DynamicCoverGroupBundleInventory::Remove(
        UFG::DynamicCoverGroupBundleInventory *this,
        UFG::DynamicCoverGroupBundle *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::DynamicCoverGroupBundle::~DynamicCoverGroupBundle(resource_data);
}

