// File Line: 17
// RVA: 0xD53210
void __fastcall hkpConstraintConstructionKit::begin(
        hkpConstraintConstructionKit *this,
        hkpGenericConstraintData *constraint)
{
  hkpGenericConstraintDataScheme *Scheme; // rax

  Scheme = hkpGenericConstraintData::getScheme(constraint);
  this->m_constraint = constraint;
  this->m_scheme = Scheme;
  *(_QWORD *)&this->m_stiffnessReference = 0i64;
  *(_QWORD *)&this->m_linearDofSpecifiedA[0].m_bool = 0i64;
  *(_WORD *)&this->m_pivotSpecifiedA.m_bool = 0;
}

// File Line: 40
// RVA: 0xD53250
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofA(
        hkpConstraintConstructionKit *this,
        hkVector4f *dof,
        int axis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  __int64 v4; // rsi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  v4 = axis;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 3;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = this->m_scheme;
  m_size = v8->m_data.m_size;
  p_m_data = &v8->m_data;
  if ( m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++] = (hkVector4f)dof->m_quad;
  this->m_linearDofSpecifiedA[v4].m_bool = 1;
  return result;
}

// File Line: 50
// RVA: 0xD53350
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofB(
        hkpConstraintConstructionKit *this,
        hkVector4f *dof,
        int axis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  __int64 v4; // rsi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  v4 = axis;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 4;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = this->m_scheme;
  m_size = v8->m_data.m_size;
  p_m_data = &v8->m_data;
  if ( m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++] = (hkVector4f)dof->m_quad;
  this->m_linearDofSpecifiedB[v4].m_bool = 1;
  return result;
}

// File Line: 60
// RVA: 0xD53450
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofWorld(
        hkpConstraintConstructionKit *this,
        hkVector4f *dof,
        int axis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  __int64 v4; // rsi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  v4 = axis;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 5;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = this->m_scheme;
  m_size = v8->m_data.m_size;
  p_m_data = &v8->m_data;
  if ( m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++] = (hkVector4f)dof->m_quad;
  this->m_linearDofSpecifiedA[v4].m_bool = 1;
  this->m_linearDofSpecifiedB[v4].m_bool = 1;
  return result;
}

// File Line: 71
// RVA: 0xD53550
void __fastcall hkpConstraintConstructionKit::constrainLinearDof(hkpConstraintConstructionKit *this, int axis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rbx
  hkpGenericConstraintDataScheme *v6; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 6;
  v5 = this->m_scheme;
  if ( v5->m_commands.m_size == (v5->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_commands.m_data, 4);
  v5->m_commands.m_data[v5->m_commands.m_size++] = axis;
  v6 = this->m_scheme;
  v6->m_info.m_sizeOfSchemas += 48;
  ++v6->m_info.m_numSolverResults;
  ++v6->m_info.m_numSolverElemTemps;
}

// File Line: 81
// RVA: 0xD53600
void __fastcall hkpConstraintConstructionKit::constrainAllLinearDof(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v3; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 7;
  v3 = this->m_scheme;
  v3->m_info.m_sizeOfSchemas += 144;
  v3->m_info.m_numSolverResults += 3;
  v3->m_info.m_numSolverElemTemps += 3;
}

// File Line: 91
// RVA: 0xD53670
__int64 __fastcall hkpConstraintConstructionKit::setAngularBasisA(
        hkpConstraintConstructionKit *this,
        hkMatrix3f *dofBasis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx
  hkpGenericConstraintDataScheme *v9; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 8;
  v5 = this->m_scheme;
  m_size = v5->m_data.m_size;
  p_m_data = &v5->m_data;
  if ( m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  p_m_data->m_data[p_m_data->m_size++] = dofBasis->m_col0;
  v8 = this->m_scheme;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v8->m_data.m_data, 16);
  v8->m_data.m_data[v8->m_data.m_size++] = dofBasis->m_col1;
  v9 = this->m_scheme;
  if ( v9->m_data.m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v9->m_data.m_data, 16);
  result = m_size;
  v9->m_data.m_data[v9->m_data.m_size++] = dofBasis->m_col2;
  this->m_angularBasisSpecifiedA.m_bool = 1;
  return result;
}

// File Line: 102
// RVA: 0xD537A0
__int64 __fastcall hkpConstraintConstructionKit::setAngularBasisB(
        hkpConstraintConstructionKit *this,
        hkMatrix3f *dofBasis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx
  hkpGenericConstraintDataScheme *v9; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 9;
  v5 = this->m_scheme;
  m_size = v5->m_data.m_size;
  p_m_data = &v5->m_data;
  if ( m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  p_m_data->m_data[p_m_data->m_size++] = dofBasis->m_col0;
  v8 = this->m_scheme;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v8->m_data.m_data, 16);
  v8->m_data.m_data[v8->m_data.m_size++] = dofBasis->m_col1;
  v9 = this->m_scheme;
  if ( v9->m_data.m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v9->m_data.m_data, 16);
  result = m_size;
  v9->m_data.m_data[v9->m_data.m_size++] = dofBasis->m_col2;
  this->m_angularBasisSpecifiedB.m_bool = 1;
  return result;
}

// File Line: 113
// RVA: 0xD538D0
void __fastcall hkpConstraintConstructionKit::setAngularBasisABodyFrame(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 10;
  this->m_angularBasisSpecifiedA.m_bool = 1;
}

// File Line: 119
// RVA: 0xD53930
void __fastcall hkpConstraintConstructionKit::setAngularBasisBBodyFrame(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 11;
  this->m_angularBasisSpecifiedB.m_bool = 1;
}

// File Line: 127
// RVA: 0xD53990
void __fastcall hkpConstraintConstructionKit::constrainToAngularDof(hkpConstraintConstructionKit *this, int axis)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rbx
  hkpGenericConstraintDataScheme *v6; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 12;
  v5 = this->m_scheme;
  if ( v5->m_commands.m_size == (v5->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v5->m_commands.m_data, 4);
  v5->m_commands.m_data[v5->m_commands.m_size++] = axis;
  v6 = this->m_scheme;
  v6->m_info.m_sizeOfSchemas += 96;
  v6->m_info.m_numSolverResults += 2;
  v6->m_info.m_numSolverElemTemps += 2;
}

// File Line: 137
// RVA: 0xD53A40
void __fastcall hkpConstraintConstructionKit::constrainAllAngularDof(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v3; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 13;
  v3 = this->m_scheme;
  v3->m_info.m_sizeOfSchemas += 144;
  v3->m_info.m_numSolverResults += 3;
  v3->m_info.m_numSolverElemTemps += 3;
}

// File Line: 147
// RVA: 0xD53AB0
__int64 __fastcall hkpConstraintConstructionKit::setPivotA(hkpConstraintConstructionKit *this, hkVector4f *pivot)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 1;
  v5 = this->m_scheme;
  m_size = v5->m_data.m_size;
  p_m_data = &v5->m_data;
  if ( m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++] = (hkVector4f)pivot->m_quad;
  this->m_pivotSpecifiedA.m_bool = 1;
  return result;
}

// File Line: 156
// RVA: 0xD53B70
__int64 __fastcall hkpConstraintConstructionKit::setPivotB(hkpConstraintConstructionKit *this, hkVector4f *pivot)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int m_size; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 2;
  v5 = this->m_scheme;
  m_size = v5->m_data.m_size;
  p_m_data = &v5->m_data;
  if ( m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++] = (hkVector4f)pivot->m_quad;
  this->m_pivotSpecifiedB.m_bool = 1;
  return result;
}

// File Line: 165
// RVA: 0xD53C30
__int64 __fastcall hkpConstraintConstructionKit::setPivotsHelper(
        hkpConstraintConstructionKit *this,
        hkpRigidBody *bodyA,
        hkpRigidBody *bodyB,
        hkVector4f *pivot)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm0
  hkVector4f v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm1
  __m128 v10; // xmm4
  __m128 v11; // xmm2
  __m128 v12; // xmm6
  __m128 v13; // xmm5
  __m128 v14; // xmm0
  hkVector4f v15; // xmm3
  __m128 v16; // xmm1
  __m128 v17; // xmm0
  __m128 v18; // xmm5
  hkVector4f v19; // xmm4
  __m128 v20; // xmm1
  hkVector4f v21; // xmm0
  __m128 v22; // xmm1
  __m128 v23; // xmm2
  unsigned int v24; // ebx
  __int64 result; // rax
  hkVector4f pivota; // [rsp+20h] [rbp-38h] BYREF
  hkVector4f v27; // [rsp+30h] [rbp-28h] BYREF

  v4.m_quad = (__m128)bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v5.m_quad = (__m128)bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v7.m_quad = (__m128)bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v8 = _mm_unpackhi_ps(v7.m_quad, v5.m_quad);
  v9 = _mm_unpacklo_ps(v7.m_quad, v5.m_quad);
  v10 = _mm_shuffle_ps(v8, v4.m_quad, 228);
  v11 = _mm_movelh_ps(v9, v4.m_quad);
  v12 = _mm_sub_ps(pivot->m_quad, bodyB->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v13 = _mm_sub_ps(pivot->m_quad, bodyA->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v14 = _mm_shuffle_ps(_mm_movehl_ps(v11, v9), v4.m_quad, 212);
  v15.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v16 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 85), v14);
  v17 = _mm_shuffle_ps(v13, v13, 0);
  v18 = _mm_mul_ps(_mm_shuffle_ps(v13, v13, 170), v10);
  v19.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v20 = _mm_add_ps(v16, _mm_mul_ps(v17, v11));
  v21.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  pivota.m_quad = _mm_add_ps(v20, v18);
  v22 = _mm_unpacklo_ps(v19.m_quad, v21.m_quad);
  v23 = _mm_movelh_ps(v22, v15.m_quad);
  v27.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 85), _mm_shuffle_ps(_mm_movehl_ps(v23, v22), v15.m_quad, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v12, v12, 0), v23)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(v12, v12, 170),
                   _mm_shuffle_ps(_mm_unpackhi_ps(v19.m_quad, v21.m_quad), v15.m_quad, 228)));
  v24 = hkpConstraintConstructionKit::setPivotA(this, &pivota);
  hkpConstraintConstructionKit::setPivotB(this, &v27);
  result = v24;
  *(_WORD *)&this->m_pivotSpecifiedA.m_bool = 257;
  return result;
}

// File Line: 183
// RVA: 0xD53D50
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkpConstraintConstructionKit::setLinearLimit(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        double min,
        double max)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v13; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 16;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = axis;
  v8 = this->m_scheme;
  v9 = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&min, (__m128)0i64), _mm_unpacklo_ps(*(__m128 *)&max, (__m128)0i64));
  m_size = v8->m_data.m_size;
  p_m_data = &v8->m_data;
  if ( m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v9;
  v13 = this->m_scheme;
  v13->m_info.m_sizeOfSchemas += 64;
  ++v13->m_info.m_numSolverResults;
  ++v13->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 197
// RVA: 0xD53E70
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkpConstraintConstructionKit::setAngularLimit(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        double min,
        double max)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v13; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 17;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = axis;
  v8 = this->m_scheme;
  v9 = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&min, (__m128)0i64), _mm_unpacklo_ps(*(__m128 *)&max, (__m128)0i64));
  m_size = v8->m_data.m_size;
  p_m_data = &v8->m_data;
  if ( m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v9;
  v13 = this->m_scheme;
  v13->m_info.m_sizeOfSchemas += 48;
  ++v13->m_info.m_numSolverResults;
  ++v13->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 212
// RVA: 0xD53F90
__int64 __fastcall hkpConstraintConstructionKit::setConeLimit(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        float angle)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v6; // rbx
  __m128i si128; // xmm6
  __m128 v8; // xmm9
  hkpGenericConstraintDataScheme *v9; // rax
  __m128 v10; // xmm2
  __m128i v11; // xmm8
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __m128i v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v21; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 18;
  v6 = this->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_commands.m_data, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = axis;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v8 = _mm_add_ps((__m128)LODWORD(angle), *(__m128 *)_xmm);
  v9 = this->m_scheme;
  v10 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  v11 = _mm_add_epi32(si128, si128);
  m_size = v9->m_data.m_size;
  p_m_data = &v9->m_data;
  v14 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v10)), si128));
  v15 = _mm_cvtepi32_ps(v14);
  v16 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v14, v11), (__m128i)0i64);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, *(__m128 *)DP1_0), v10), _mm_mul_ps(v15, *(__m128 *)DP2)),
          _mm_mul_ps(v15, *(__m128 *)DP3));
  v18 = _mm_mul_ps(v17, v17);
  v19 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            _mm_xor_ps(
              _mm_or_ps(
                _mm_andnot_ps(
                  v16,
                  _mm_add_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v18),
                            *(__m128 *)cosCoeff2_0),
                          v18),
                        v18),
                      _mm_mul_ps(v18, *(__m128 *)_xmm)),
                    *(__m128 *)_xmm)),
                _mm_and_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v18, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v18),
                          *(__m128 *)sinCoeff2_0),
                        v18),
                      v17),
                    v17),
                  v16)),
              _mm_xor_ps(
                (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v11, v11), v14), 0x1Du),
                _mm_and_ps(v8, *(__m128 *)_xmm))),
            (__m128)0i64),
          (__m128)_xmm);
  if ( m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v19;
  v21 = this->m_scheme;
  v21->m_info.m_sizeOfSchemas += 48;
  ++v21->m_info.m_numSolverResults;
  ++v21->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 227
// RVA: 0xD541D0
__int64 __fastcall hkpConstraintConstructionKit::setTwistLimit(
        hkpConstraintConstructionKit *this,
        unsigned __int8 twistAxis,
        unsigned __int8 planeAxis,
        float min,
        float max)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v9; // rbx
  hkpGenericConstraintDataScheme *v10; // rbx
  __m128i si128; // xmm3
  __m128 v12; // xmm2
  __m128i v13; // xmm5
  __m128 v14; // xmm4
  __m128 v15; // xmm0
  __m128 v16; // xmm3
  __m128 v17; // xmm2
  __m128 v18; // xmm2
  __m128i v19; // xmm0
  __m128i v20; // xmm0
  __m128 v21; // xmm1
  hkpGenericConstraintDataScheme *v22; // rax
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __m128 v25; // xmm5
  __m128 v26; // xmm4
  __m128 v27; // xmm2
  __m128 v28; // xmm6
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v30; // rcx
  unsigned int v31; // [rsp+20h] [rbp-58h]
  __m128i v32; // [rsp+30h] [rbp-48h]

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 19;
  v9 = this->m_scheme;
  if ( v9->m_commands.m_size == (v9->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v9->m_commands.m_data, 4);
  v9->m_commands.m_data[v9->m_commands.m_size++] = twistAxis;
  v10 = this->m_scheme;
  if ( v10->m_commands.m_size == (v10->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v10->m_commands.m_data, 4);
  v10->m_commands.m_data[v10->m_commands.m_size++] = planeAxis;
  si128 = _mm_load_si128((const __m128i *)_xmm);
  v12 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(max));
  v32 = _mm_add_epi32(si128, si128);
  v13 = _mm_andnot_si128(si128, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v12, *(__m128 *)_xmm)), si128));
  v14 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v13, v32), (__m128i)0i64);
  v15 = _mm_cvtepi32_ps(v13);
  v16 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v15, *(__m128 *)DP1_0), v12), _mm_mul_ps(v15, *(__m128 *)DP2)),
          _mm_mul_ps(v15, *(__m128 *)DP3));
  v17 = _mm_mul_ps(v16, v16);
  v31 = (_mm_andnot_ps(
           v14,
           _mm_add_ps(
             _mm_sub_ps(
               _mm_mul_ps(
                 _mm_mul_ps(
                   _mm_add_ps(
                     _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v17, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v17),
                     *(__m128 *)cosCoeff2_0),
                   v17),
                 v17),
               _mm_mul_ps(v17, *(__m128 *)_xmm)),
             *(__m128 *)_xmm)).m128_u32[0] | COERCE_UNSIGNED_INT(
                                               (float)((float)((float)((float)((float)((float)(v17.m128_f32[0]
                                                                                             * -0.00019515296)
                                                                                     + 0.0083321612)
                                                                             * v17.m128_f32[0])
                                                                     + -0.16666655)
                                                             * v17.m128_f32[0])
                                                     * v16.m128_f32[0])
                                             + v16.m128_f32[0]) & v14.m128_i32[0]) ^ (_mm_and_si128(
                                                                                        _mm_add_epi32(v32, v32),
                                                                                        v13).m128i_u32[0] << 29) ^ LODWORD(max) & _xmm[0];
  v18 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(min));
  v19 = _mm_load_si128((const __m128i *)_xmm);
  v20 = _mm_andnot_si128(v19, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v18, *(__m128 *)_xmm)), v19));
  v21 = _mm_cvtepi32_ps(v20);
  v22 = this->m_scheme;
  m_size = v22->m_data.m_size;
  p_m_data = &v22->m_data;
  v25 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v20, v32), (__m128i)0i64);
  v26 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v21, *(__m128 *)DP1_0), v18), _mm_mul_ps(v21, *(__m128 *)DP2)),
          _mm_mul_ps(v21, *(__m128 *)DP3));
  v27 = _mm_mul_ps(v26, v26);
  v28 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            _mm_xor_ps(
              _mm_xor_ps(
                _mm_and_ps((__m128)LODWORD(min), *(__m128 *)_xmm),
                (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v32, v32), v20), 0x1Du)),
              _mm_or_ps(
                _mm_andnot_ps(
                  v25,
                  _mm_add_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v27),
                            *(__m128 *)cosCoeff2_0),
                          v27),
                        v27),
                      _mm_mul_ps(v27, *(__m128 *)_xmm)),
                    *(__m128 *)_xmm)),
                _mm_and_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v27, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v27),
                          *(__m128 *)sinCoeff2_0),
                        v27),
                      v26),
                    v26),
                  v25))),
            (__m128)0i64),
          _mm_unpacklo_ps((__m128)v31, (__m128)0i64));
  if ( m_size == (v22->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v28;
  v30 = this->m_scheme;
  v30->m_info.m_sizeOfSchemas += 48;
  ++v30->m_info.m_numSolverResults;
  ++v30->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 245
// RVA: 0xD54560
__int64 __fastcall hkpConstraintConstructionKit::setAngularMotor(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        hkpConstraintMotor *motor)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int m_size; // ebp
  __m128 v11; // xmm6
  hkpGenericConstraintDataScheme *v12; // rbx
  hkpGenericConstraintDataScheme *v13; // rbx
  hkpGenericConstraintDataScheme *v14; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 14;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = axis;
  v8 = this->m_scheme;
  v9 = 0i64;
  m_size = v8->m_data.m_size;
  v9.m128_f32[0] = (float)v8->m_motors.m_size;
  v11 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)0i64),
          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  hkReferencedObject::addReference(motor);
  v12 = this->m_scheme;
  if ( v12->m_data.m_size == (v12->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v12->m_data.m_data, 16);
  v12->m_data.m_data[v12->m_data.m_size++].m_quad = v11;
  v13 = this->m_scheme;
  if ( v13->m_motors.m_size == (v13->m_motors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v13->m_motors.m_data, 8);
  v13->m_motors.m_data[v13->m_motors.m_size++] = motor;
  v14 = this->m_scheme;
  v14->m_info.m_sizeOfSchemas += 64;
  v14->m_info.m_numSolverResults += 2;
  v14->m_info.m_numSolverElemTemps += 2;
  return m_size;
}

// File Line: 266
// RVA: 0xD546C0
__int64 __fastcall hkpConstraintConstructionKit::setLinearMotor(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        hkpConstraintMotor *motor)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int m_size; // ebp
  __m128 v11; // xmm6
  hkpGenericConstraintDataScheme *v12; // rbx
  hkpGenericConstraintDataScheme *v13; // rbx
  hkpGenericConstraintDataScheme *v14; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 15;
  v7 = this->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_commands.m_data, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = axis;
  v8 = this->m_scheme;
  v9 = 0i64;
  m_size = v8->m_data.m_size;
  v9.m128_f32[0] = (float)v8->m_motors.m_size;
  v11 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)0i64),
          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  hkReferencedObject::addReference(motor);
  v12 = this->m_scheme;
  if ( v12->m_data.m_size == (v12->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v12->m_data.m_data, 16);
  v12->m_data.m_data[v12->m_data.m_size++].m_quad = v11;
  v13 = this->m_scheme;
  if ( v13->m_motors.m_size == (v13->m_motors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v13->m_motors.m_data, 8);
  v13->m_motors.m_data[v13->m_motors.m_size++] = motor;
  v14 = this->m_scheme;
  v14->m_info.m_sizeOfSchemas += 80;
  v14->m_info.m_numSolverResults += 2;
  v14->m_info.m_numSolverElemTemps += 2;
  return m_size;
}

// File Line: 288
// RVA: 0xD54820
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkpConstraintConstructionKit::setAngularFriction(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        double maxImpulse)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v6; // rbx
  hkpGenericConstraintDataScheme *v7; // rax
  __m128 v8; // xmm6
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v12; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 20;
  v6 = this->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_commands.m_data, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = axis;
  v7 = this->m_scheme;
  v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&maxImpulse, (__m128)0i64), (__m128)0i64);
  m_size = v7->m_data.m_size;
  p_m_data = &v7->m_data;
  if ( m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v8;
  v12 = this->m_scheme;
  v12->m_info.m_sizeOfSchemas += 48;
  v12->m_info.m_numSolverResults += 2;
  v12->m_info.m_numSolverElemTemps += 2;
  return result;
}

// File Line: 301
// RVA: 0xD54930
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkpConstraintConstructionKit::setLinearFriction(
        hkpConstraintConstructionKit *this,
        unsigned __int8 axis,
        double maxImpulse)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v6; // rbx
  hkpGenericConstraintDataScheme *v7; // rax
  __m128 v8; // xmm6
  unsigned int m_size; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v12; // rcx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 21;
  v6 = this->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v6->m_commands.m_data, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = axis;
  v7 = this->m_scheme;
  v8 = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&maxImpulse, (__m128)0i64), (__m128)0i64);
  m_size = v7->m_data.m_size;
  p_m_data = &v7->m_data;
  if ( m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v8;
  v12 = this->m_scheme;
  v12->m_info.m_sizeOfSchemas += 64;
  v12->m_info.m_numSolverResults += 2;
  v12->m_info.m_numSolverElemTemps += 2;
  return result;
}

// File Line: 319
// RVA: 0xD54A40
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall hkpConstraintConstructionKit::setStrength(hkpConstraintConstructionKit *this, double strength)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v4; // rax
  __m128 v5; // xmm6
  unsigned int m_size; // edi
  hkArray<hkVector4f,hkContainerHeapAllocator> *p_m_data; // rbx
  __int64 result; // rax

  m_scheme = this->m_scheme;
  ++this->m_stiffnessReference;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 22;
  v4 = this->m_scheme;
  v5 = _mm_unpacklo_ps(_mm_unpacklo_ps(*(__m128 *)&strength, (__m128)0i64), (__m128)0i64);
  m_size = v4->m_data.m_size;
  p_m_data = &v4->m_data;
  if ( m_size == (v4->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&p_m_data->m_data, 16);
  result = m_size;
  p_m_data->m_data[p_m_data->m_size++].m_quad = v5;
  return result;
}

// File Line: 331
// RVA: 0xD54B00
void __fastcall hkpConstraintConstructionKit::restoreStrength(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx

  m_scheme = this->m_scheme;
  --this->m_stiffnessReference;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 23;
}

// File Line: 339
// RVA: 0xD54B50
void __fastcall hkpConstraintConstructionKit::addConstraintModifierCallback(
        hkpConstraintConstructionKit *this,
        hkpConstraintModifier *cm,
        int userData)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 24;
  v7 = this->m_scheme;
  if ( v7->m_modifiers.m_size == (v7->m_modifiers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v7->m_modifiers.m_data, 8);
  v7->m_modifiers.m_data[v7->m_modifiers.m_size++] = cm;
  v8 = this->m_scheme;
  if ( v8->m_commands.m_size == (v8->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&v8->m_commands.m_data, 4);
  v8->m_commands.m_data[v8->m_commands.m_size++] = userData;
}

// File Line: 348
// RVA: 0xD54C30
void __fastcall hkpConstraintConstructionKit::end(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *m_scheme; // rbx

  m_scheme = this->m_scheme;
  if ( m_scheme->m_commands.m_size == (m_scheme->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, (const void **)&m_scheme->m_commands.m_data, 4);
  m_scheme->m_commands.m_data[m_scheme->m_commands.m_size++] = 0;
}

// File Line: 356
// RVA: 0xD54C80
void __fastcall hkpConstraintConstructionKit::computeConstraintInfo(
        hkArray<int,hkContainerHeapAllocator> *commands,
        hkpConstraintInfo *info)
{
  int *m_data; // r8
  int *v3; // r9

  m_data = commands->m_data;
  v3 = &commands->m_data[commands->m_size];
  if ( commands->m_data < v3 )
  {
    while ( 2 )
    {
      switch ( *m_data )
      {
        case 0:
          return;
        case 3:
        case 4:
        case 5:
        case 24:
          ++m_data;
          goto LABEL_12;
        case 6:
        case 17:
        case 18:
          info->m_sizeOfSchemas += 48;
          ++info->m_numSolverResults;
          ++m_data;
          ++info->m_numSolverElemTemps;
          goto LABEL_12;
        case 7:
        case 13:
          info->m_sizeOfSchemas += 144;
          info->m_numSolverResults += 3;
          info->m_numSolverElemTemps += 3;
          goto LABEL_12;
        case 12:
          info->m_sizeOfSchemas += 96;
          info->m_numSolverResults += 2;
          ++m_data;
          info->m_numSolverElemTemps += 2;
          goto LABEL_12;
        case 14:
        case 21:
          info->m_sizeOfSchemas += 64;
          info->m_numSolverResults += 2;
          ++m_data;
          info->m_numSolverElemTemps += 2;
          goto LABEL_12;
        case 15:
          info->m_sizeOfSchemas += 80;
          info->m_numSolverResults += 2;
          ++m_data;
          info->m_numSolverElemTemps += 2;
          goto LABEL_12;
        case 16:
          info->m_sizeOfSchemas += 64;
          ++info->m_numSolverResults;
          ++m_data;
          ++info->m_numSolverElemTemps;
          goto LABEL_12;
        case 19:
          info->m_sizeOfSchemas += 48;
          ++info->m_numSolverResults;
          m_data += 2;
          ++info->m_numSolverElemTemps;
          goto LABEL_12;
        case 20:
          info->m_sizeOfSchemas += 48;
          info->m_numSolverResults += 2;
          ++m_data;
          info->m_numSolverElemTemps += 2;
          goto LABEL_12;
        default:
LABEL_12:
          if ( ++m_data >= v3 )
            return;
          continue;
      }
    }
  }
}

