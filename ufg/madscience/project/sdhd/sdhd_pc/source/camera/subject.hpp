// File Line: 26
// RVA: 0x3BECB0
UFG::ComponentIDDesc *__fastcall UFG::CameraSubject::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::CameraSubject::_DescInit )
  {
    UFG::CameraSubject::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
    UFG::CameraSubject::_DescInit = 1;
    UFG::CameraSubject::_TypeUID = UFG::CameraSubject::_TypeIDesc.mChildBitMask | (UFG::CameraSubject::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::CameraSubject::_CameraSubjectTypeUID = UFG::CameraSubject::_TypeIDesc.mChildBitMask | (UFG::CameraSubject::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::CameraSubject::_TypeIDesc;
}

// File Line: 46
// RVA: 0x3C3F30
UFG::qVector3 *__fastcall UFG::CameraSubject::GetUp(UFG::CameraSubject *this)
{
  return (UFG::qVector3 *)(((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[18].__vecDelDtor)(this) + 32);
}

// File Line: 47
// RVA: 0x3C3560
UFG::qVector3 *__fastcall UFG::CameraSubject::GetLeft(UFG::CameraSubject *this)
{
  return (UFG::qVector3 *)(((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[18].__vecDelDtor)(this) + 16);
}

// File Line: 48
// RVA: 0x3C3410
UFG::qVector3 *__fastcall UFG::CameraSubject::GetForward(UFG::CameraSubject *this)
{
  return (UFG::qVector3 *)((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[18].__vecDelDtor)(this);
}

// File Line: 49
// RVA: 0x3C3960
UFG::qVector3 *__fastcall UFG::CameraSubject::GetPosition(UFG::CameraSubject *this)
{
  return (UFG::qVector3 *)(((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[18].__vecDelDtor)(this) + 48);
}

// File Line: 50
// RVA: 0x3C3580
UFG::qMatrix44 *__fastcall UFG::CameraSubject::GetLocalWorld(UFG::CameraSubject *this)
{
  return &this->mLocalWorld;
}

// File Line: 51
// RVA: 0x3C43C0
UFG::qMatrix44 *__fastcall Scaleform::Render::HAL::GetRQProcessor(UFG::CameraSubject *this)
{
  return &this->mWorldLocal;
}

// File Line: 57
// RVA: 0x3C28B0
UFG::qVector3 *__fastcall UFG::CameraSubject::GetBoxMax(UFG::CameraSubject *this)
{
  return &UFG::qVector3::msZero;
}

// File Line: 70
// RVA: 0x3C3980
float __fastcall UFG::CameraSubject::GetSpeed(UFG::CameraSubject *this)
{
  float *v1; // rax
  __m128 v2; // xmm2
  float result; // xmm0_4

  v1 = (float *)((__int64 (__fastcall *)(UFG::CameraSubject *))this->vfptr[20].__vecDelDtor)(this);
  v2 = (__m128)*(unsigned int *)v1;
  v2.m128_f32[0] = (float)((float)(v2.m128_f32[0] * v2.m128_f32[0]) + (float)(v1[1] * v1[1])) + (float)(v1[2] * v1[2]);
  LODWORD(result) = _mm_sqrt_ps(v2).m128_u32[0];
  return result;
}

// File Line: 88
// RVA: 0x3C5F00
bool __fastcall Scaleform::Render::Text::DocView::DocumentListener::View_OnLineFormat(
        hkgpIndexedMesh::EdgeBarrier *this,
        hkgpIndexedMeshDefinitions::Edge *e)
{
  return 0;
}

