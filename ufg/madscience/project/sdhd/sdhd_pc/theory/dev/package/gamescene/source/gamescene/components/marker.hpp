// File Line: 89
// RVA: 0x239110
UFG::ComponentIDDesc *__fastcall UFG::MarkerBase::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::MarkerBase::_DescInit )
  {
    v0 = UFG::HintComponentBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::MarkerBase::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::MarkerBase::_TypeIDesc.mChildBitMask = v1;
    UFG::MarkerBase::_TypeIDesc.mChildren = 0;
    UFG::MarkerBase::_DescInit = 1;
    UFG::MarkerBase::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::MarkerBase::_MarkerBaseTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::MarkerBase::_TypeIDesc;
}

// File Line: 169
// RVA: 0x239080
UFG::ComponentIDDesc *__fastcall UFG::Marker::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::Marker::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::Marker::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::Marker::_TypeIDesc.mChildBitMask = v1;
    UFG::Marker::_TypeIDesc.mChildren = 0;
    UFG::Marker::_DescInit = 1;
    UFG::Marker::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::Marker::_MarkerTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::Marker::_TypeIDesc;
}

// File Line: 201
// RVA: 0x238F80
UFG::ComponentIDDesc *__fastcall UFG::CameraMarker::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::CameraMarker::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::CameraMarker::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::CameraMarker::_TypeIDesc.mChildBitMask = v1;
    UFG::CameraMarker::_TypeIDesc.mChildren = 0;
    UFG::CameraMarker::_DescInit = 1;
    UFG::CameraMarker::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::CameraMarker::_CameraMarkerTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::CameraMarker::_TypeIDesc;
}

// File Line: 204
// RVA: 0x23E1E0
signed __int64 __fastcall UFG::CameraMarker::GetType(UFG::CameraMarker *this)
{
  return 4096i64;
}

// File Line: 236
// RVA: 0x238EF0
UFG::ComponentIDDesc *__fastcall UFG::AIMarker::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  int v1; // edx
  _DWORD v3[6]; // [rsp+20h] [rbp-18h]

  if ( !UFG::AIMarker::_DescInit )
  {
    v0 = UFG::MarkerBase::AccessComponentDesc();
    ++UFG::HintComponentBase::_TypeIDesc.mChildren;
    v1 = v0->mChildBitMask | (1 << SLOBYTE(UFG::HintComponentBase::_TypeIDesc.mChildren));
    LOWORD(v3[0]) = v0->mBaseTypeIndex;
    *(_DWORD *)&UFG::AIMarker::_TypeIDesc.mBaseTypeIndex = v3[0];
    UFG::AIMarker::_TypeIDesc.mChildBitMask = v1;
    UFG::AIMarker::_TypeIDesc.mChildren = 0;
    UFG::AIMarker::_DescInit = 1;
    UFG::AIMarker::_TypeUID = v1 | (LOWORD(v3[0]) << 25);
    UFG::AIMarker::_AIMarkerTypeUID = v1 | (LOWORD(v3[0]) << 25);
  }
  return &UFG::AIMarker::_TypeIDesc;
}

