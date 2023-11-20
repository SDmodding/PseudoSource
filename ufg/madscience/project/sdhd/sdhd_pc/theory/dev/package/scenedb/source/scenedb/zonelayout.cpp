// File Line: 36
// RVA: 0x1470450
__int64 UFG::_dynamic_initializer_for__gZoneLayoutEvent__()
{
  UFG::ChannelObj::ChannelObj(&UFG::gZoneLayoutEvent, "ZoneLayoutEvent", 0i64);
  return atexit(UFG::_dynamic_atexit_destructor_for__gZoneLayoutEvent__);
}

// File Line: 53
// RVA: 0x1470480
__int64 UFG::_dynamic_initializer_for__gZoneLayoutInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gZoneLayoutInventory.vfptr,
    "ZoneLayout",
    0xC35E39D5,
    0x43FF83A9u,
    0,
    0);
  UFG::gZoneLayoutInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ZoneLayoutInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gZoneLayoutInventory__);
}

// File Line: 61
// RVA: 0x2302D0
void __fastcall UFG::ZoneLayoutInventory::Add(UFG::ZoneLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::ZoneLayout *v2; // rbx
  UFG::ZoneLayoutInventory *v3; // rdi

  v2 = (UFG::ZoneLayout *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::qResourceData::qResourceData(resource_data);
  UFG::gZoneLayout = v2;
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
}

// File Line: 76
// RVA: 0x235060
void __fastcall UFG::ZoneLayoutInventory::Remove(UFG::ZoneLayoutInventory *this, UFG::qResourceData *resource_data)
{
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::gZoneLayout = 0i64;
  if ( UFG::ZoneLayout::smDebugText )
  {
    operator delete[](UFG::ZoneLayout::smDebugText);
    UFG::ZoneLayout::smDebugText = 0i64;
  }
}

// File Line: 277
// RVA: 0x232610
signed __int64 __fastcall UFG::ZoneTag::GetCurrentZone()
{
  char *v0; // r8
  __int64 v1; // rcx
  char *v2; // rdx
  unsigned __int16 v3; // r9
  __int64 v4; // rcx

  v0 = 0i64;
  v1 = UFG::gSectionLayout->mSectionVis.mOffset;
  if ( v1 )
    v2 = (char *)&UFG::gSectionLayout->mSectionVis + v1;
  else
    v2 = 0i64;
  v3 = *(_WORD *)&v2[96 * UFG::ZoneTag::sVisibleIndex + 68];
  if ( v3 == -1 )
    return 18507i64;
  v4 = UFG::gZoneLayout->mZones.mOffset;
  if ( v4 )
    v0 = (char *)&UFG::gZoneLayout->mZones + v4;
  return v0[64 * (unsigned __int64)v3 + 37] | (unsigned int)(v0[64 * (unsigned __int64)v3 + 36] << 8);
}

// File Line: 293
// RVA: 0x235750
void __fastcall UFG::ZoneTag::Update(unsigned int visIndex)
{
  UFG::allocator::free_link *v1; // rax
  UFG::Event *v2; // rbx
  UFG::allocator::free_link *v3; // rax

  if ( UFG::ZoneTag::sVisibleIndex != visIndex )
  {
    UFG::ZoneTag::sVisibleIndex = visIndex;
    v1 = UFG::qMalloc(0x38ui64, "ZoneLayoutEvent", 0i64);
    v2 = (UFG::Event *)v1;
    if ( v1 )
    {
      v3 = v1 + 1;
      v3->mNext = v3;
      v3[1].mNext = v3;
      v2->vfptr = (UFG::EventVtbl *)&UFG::Event::`vftable';
      v2->m_NamePTR = "ZoneLayoutEvent";
      v2->m_EventUID = UFG::qStringHash32("ZoneLayoutEvent", 0xFFFFFFFF);
    }
    else
    {
      v2 = 0i64;
    }
    UFG::EventDispatcher::QueueEvent(&UFG::EventDispatcher::mInstance, v2);
  }
}

