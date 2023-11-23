// File Line: 32
// RVA: 0x140F00
void __fastcall UFG::Audio3D::~Audio3D(UFG::Audio3D *this)
{
  unsigned int *p; // rcx

  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable;
  p = this->m_myIds.p;
  if ( p )
    operator delete[](p);
  this->m_myIds.p = 0i64;
  *(_QWORD *)&this->m_myIds.size = 0i64;
}

// File Line: 98
// RVA: 0x13FEE0
void __fastcall UFG::Audio3DListener::Audio3DListener(UFG::Audio3DListener *this)
{
  UFG::qVector4 v1; // xmm1
  UFG::qVector4 v2; // xmm2
  UFG::qVector4 v3; // xmm3

  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable;
  this->m_myIds.p = 0i64;
  *(_QWORD *)&this->m_myIds.size = 0i64;
  v1 = UFG::qMatrix44::msIdentity.v1;
  v2 = UFG::qMatrix44::msIdentity.v2;
  v3 = UFG::qMatrix44::msIdentity.v3;
  this->m_matrix.v0 = UFG::qMatrix44::msIdentity.v0;
  this->m_matrix.v1 = v1;
  this->m_matrix.v2 = v2;
  this->m_matrix.v3 = v3;
  *(_QWORD *)&this->m_velocity.x = 0i64;
  this->m_velocity.z = 0.0;
  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3DListener::`vftable;
}

// File Line: 102
// RVA: 0x140F40
void __fastcall UFG::Audio3DListener::~Audio3DListener(UFG::Audio3DListener *this)
{
  unsigned int *p; // rcx
  unsigned int *v3; // rcx

  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3DListener::`vftable;
  p = this->m_myIds.p;
  if ( p )
    operator delete[](p);
  this->m_myIds.p = 0i64;
  *(_QWORD *)&this->m_myIds.size = 0i64;
  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable;
  v3 = this->m_myIds.p;
  if ( v3 )
    operator delete[](v3);
  this->m_myIds.p = 0i64;
  *(_QWORD *)&this->m_myIds.size = 0i64;
}

// File Line: 107
// RVA: 0x14D1A0
void __fastcall UFG::Audio3DListener::Update(UFG::Audio3DListener *this)
{
  float x; // xmm1_4
  __int64 v3; // rdi
  unsigned int v4; // eax
  float z; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  signed int size; // ecx
  float v9; // esi
  __int64 v10; // r14
  signed int v11; // ecx
  AkListenerPosition in_Position; // [rsp+8h] [rbp-29h] BYREF
  __int64 v13; // [rsp+38h] [rbp+7h]
  float v14; // [rsp+40h] [rbp+Fh]

  x = this->m_matrix.v3.x;
  LODWORD(v3) = 0;
  v4 = -1;
  LODWORD(v13) = LODWORD(this->m_matrix.v3.y) ^ _xmm[0];
  z = this->m_matrix.v3.z;
  v14 = x;
  v6 = this->m_matrix.v0.x;
  *((float *)&v13 + 1) = z;
  LODWORD(in_Position.OrientationFront.X) = LODWORD(this->m_matrix.v0.y) ^ _xmm[0];
  v7 = this->m_matrix.v0.z;
  in_Position.OrientationFront.Z = v6;
  size = this->m_myIds.size;
  in_Position.OrientationFront.Y = v7;
  if ( size > 0 )
    v4 = *this->m_myIds.p;
  if ( v4 != -1 )
  {
    v9 = v14;
    v10 = v13;
    do
    {
      *(_QWORD *)&in_Position.Position.X = v10;
      in_Position.Position.Z = v9;
      AK::SoundEngine::SetListenerPosition(&in_Position, v4);
      v11 = this->m_myIds.size;
      v3 = (unsigned int)(v3 + 1);
      v4 = -1;
      if ( v11 )
      {
        if ( (int)v3 < v11 )
          v4 = this->m_myIds.p[v3];
      }
    }
    while ( v4 != -1 );
  }
}

