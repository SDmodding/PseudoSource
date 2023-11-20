// File Line: 38
// RVA: 0x5B2620
UFG::ComponentIDDesc *__fastcall UFG::VehicleSpot::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::VehicleSpot::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::VehicleSpot::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::VehicleSpot::_TypeIDesc.mChildBitMask = v1;
    UFG::VehicleSpot::_TypeIDesc.mChildren = 0;
    UFG::VehicleSpot::_DescInit = 1;
    UFG::VehicleSpot::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::VehicleSpot::_VehicleSpotTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::VehicleSpot::_TypeIDesc;
}

// File Line: 51
// RVA: 0x5B3E70
__int64 __fastcall UFG::VehicleSpot::GetRoadNetworkType(UFG::VehicleSpot *this)
{
  return this->mRoadNetworkType;
}

// File Line: 53
// RVA: 0x5B2D20
_BOOL8 __fastcall UFG::VehicleSpot::CanSpawn(UFG::VehicleSpot *this)
{
  return this->mCanSpawn != 0;
}

// File Line: 100
// RVA: 0x5B2470
UFG::ComponentIDDesc *__fastcall UFG::ParkingSpot::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::ParkingSpot::_DescInit )
  {
    v0 = UFG::VehicleSpot::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::ParkingSpot::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::ParkingSpot::_TypeIDesc.mChildBitMask = v1;
    UFG::ParkingSpot::_TypeIDesc.mChildren = 0;
    UFG::ParkingSpot::_DescInit = 1;
    UFG::ParkingSpot::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::ParkingSpot::_ParkingSpotTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::ParkingSpot::_TypeIDesc;
}

