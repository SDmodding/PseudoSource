// File Line: 32
// RVA: 0x140F00
void __fastcall UFG::Audio3D::~Audio3D(UFG::Audio3D *this)
{
  UFG::Audio3D *v1; // rbx
  unsigned int *v2; // rcx

  v1 = this;
  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable';
  v2 = this->m_myIds.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_myIds.p = 0i64;
  *(_QWORD *)&v1->m_myIds.size = 0i64;
}

// File Line: 98
// RVA: 0x13FEE0
void __fastcall UFG::Audio3DListener::Audio3DListener(UFG::Audio3DListener *this)
{
  UFG::qVector4 v1; // xmm1
  UFG::qVector4 v2; // xmm2
  UFG::qVector4 v3; // xmm3

  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable';
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
  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3DListener::`vftable';
}

// File Line: 102
// RVA: 0x140F40
void __fastcall UFG::Audio3DListener::~Audio3DListener(UFG::Audio3DListener *this)
{
  UFG::Audio3DListener *v1; // rbx
  unsigned int *v2; // rcx
  unsigned int *v3; // rcx

  v1 = this;
  this->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3DListener::`vftable';
  v2 = this->m_myIds.p;
  if ( v2 )
    operator delete[](v2);
  v1->m_myIds.p = 0i64;
  *(_QWORD *)&v1->m_myIds.size = 0i64;
  v1->vfptr = (UFG::Audio3DVtbl *)&UFG::Audio3D::`vftable';
  v3 = v1->m_myIds.p;
  if ( v3 )
    operator delete[](v3);
  v1->m_myIds.p = 0i64;
  *(_QWORD *)&v1->m_myIds.size = 0i64;
}

// File Line: 107
// RVA: 0x14D1A0
void __fastcall UFG::Audio3DListener::Update(UFG::Audio3DListener *this)
{
  float v1; // xmm1_4
  UFG::Audio3DListener *v2; // rbx
  __int64 v3; // rdi
  unsigned int v4; // eax
  __int128 v5; // xmm7
  __int128 v6; // xmm8
  __m128 v7; // xmm6
  float v8; // xmm0_4
  float v9; // xmm1_4
  float v10; // xmm0_4
  signed int v11; // ecx
  float v12; // esi
  __int64 v13; // r14
  signed int v14; // ecx
  AkListenerPosition in_Position; // [rsp+8h] [rbp-29h]
  __int64 v16; // [rsp+38h] [rbp+7h]
  float v17; // [rsp+40h] [rbp+Fh]

  v1 = this->m_matrix.v3.x;
  v2 = this;
  LODWORD(v3) = 0;
  v4 = -1;
  v5 = LODWORD(this->m_matrix.v2.z);
  v6 = LODWORD(this->m_matrix.v2.x);
  v7 = _mm_xor_ps((__m128)LODWORD(this->m_matrix.v2.y), (__m128)(unsigned int)_xmm[0]);
  LODWORD(v16) = LODWORD(this->m_matrix.v3.y) ^ _xmm[0];
  v8 = this->m_matrix.v3.z;
  v17 = v1;
  v9 = this->m_matrix.v0.x;
  *((float *)&v16 + 1) = v8;
  LODWORD(in_Position.OrientationFront.X) = LODWORD(this->m_matrix.v0.y) ^ _xmm[0];
  v10 = this->m_matrix.v0.z;
  in_Position.OrientationFront.Z = v9;
  v11 = this->m_myIds.size;
  in_Position.OrientationFront.Y = v10;
  if ( v11 > 0 )
    v4 = *v2->m_myIds.p;
  if ( v4 != -1 )
  {
    v12 = v17;
    v13 = v16;
    do
    {
      *(_QWORD *)&in_Position.Position.X = v13;
      in_Position.Position.Z = v12;
      AK::SoundEngine::SetListenerPosition(&in_Position, v4);
      v14 = v2->m_myIds.size;
      v3 = (unsigned int)(v3 + 1);
      v4 = -1;
      if ( v14 )
      {
        if ( (signed int)v3 < v14 )
          v4 = v2->m_myIds.p[v3];
      }
    }
    while ( v4 != -1 );
  }
}

