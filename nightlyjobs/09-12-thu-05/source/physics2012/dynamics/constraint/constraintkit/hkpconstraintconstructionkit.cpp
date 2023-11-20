// File Line: 17
// RVA: 0xD53210
void __fastcall hkpConstraintConstructionKit::begin(hkpConstraintConstructionKit *this, hkpGenericConstraintData *constraint)
{
  hkpConstraintConstructionKit *v2; // rdi
  hkpGenericConstraintData *v3; // rbx
  hkpGenericConstraintDataScheme *v4; // rax

  v2 = this;
  v3 = constraint;
  v4 = hkpGenericConstraintData::getScheme(constraint);
  v2->m_constraint = v3;
  v2->m_scheme = v4;
  *(_QWORD *)&v2->m_stiffnessReference = 0i64;
  *(_QWORD *)&v2->m_linearDofSpecifiedA[0].m_bool = 0i64;
  *(_WORD *)&v2->m_pivotSpecifiedA.m_bool = 0;
}

// File Line: 40
// RVA: 0xD53250
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofA(hkpConstraintConstructionKit *this, hkVector4f *dof, int axis)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  __int64 v4; // rsi
  hkVector4f *v5; // r14
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int v9; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  __int64 result; // rax

  v3 = this->m_scheme;
  v4 = axis;
  v5 = dof;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v3->m_commands.m_data[v3->m_commands.m_size++] = 3;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = v6->m_scheme;
  v9 = v8->m_data.m_size;
  v10 = &v8->m_data;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
  result = v9;
  v10->m_data[v10->m_size++] = (hkVector4f)v5->m_quad;
  v6->m_linearDofSpecifiedA[v4].m_bool = 1;
  return result;
}

// File Line: 50
// RVA: 0xD53350
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofB(hkpConstraintConstructionKit *this, hkVector4f *dof, int axis)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  __int64 v4; // rsi
  hkVector4f *v5; // r14
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int v9; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  __int64 result; // rax

  v3 = this->m_scheme;
  v4 = axis;
  v5 = dof;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v3->m_commands.m_data[v3->m_commands.m_size++] = 4;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = v6->m_scheme;
  v9 = v8->m_data.m_size;
  v10 = &v8->m_data;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
  result = v9;
  v10->m_data[v10->m_size++] = (hkVector4f)v5->m_quad;
  v6->m_linearDofSpecifiedB[v4].m_bool = 1;
  return result;
}

// File Line: 60
// RVA: 0xD53450
__int64 __fastcall hkpConstraintConstructionKit::setLinearDofWorld(hkpConstraintConstructionKit *this, hkVector4f *dof, int axis)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  __int64 v4; // rsi
  hkVector4f *v5; // r14
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  unsigned int v9; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  __int64 result; // rax

  v3 = this->m_scheme;
  v4 = axis;
  v5 = dof;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v3->m_commands.m_data[v3->m_commands.m_size++] = 5;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v4;
  v8 = v6->m_scheme;
  v9 = v8->m_data.m_size;
  v10 = &v8->m_data;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
  result = v9;
  v10->m_data[v10->m_size++] = (hkVector4f)v5->m_quad;
  v6->m_linearDofSpecifiedA[v4].m_bool = 1;
  v6->m_linearDofSpecifiedB[v4].m_bool = 1;
  return result;
}

// File Line: 71
// RVA: 0xD53550
void __fastcall hkpConstraintConstructionKit::constrainLinearDof(hkpConstraintConstructionKit *this, int axis)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  int v3; // esi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rbx
  hkpGenericConstraintDataScheme *v6; // rax

  v2 = this->m_scheme;
  v3 = axis;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 6;
  v5 = v4->m_scheme;
  if ( v5->m_commands.m_size == (v5->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_commands, 4);
  v5->m_commands.m_data[v5->m_commands.m_size++] = v3;
  v6 = v4->m_scheme;
  v6->m_info.m_sizeOfSchemas += 48;
  ++v6->m_info.m_numSolverResults;
  ++v6->m_info.m_numSolverElemTemps;
}

// File Line: 81
// RVA: 0xD53600
void __fastcall hkpConstraintConstructionKit::constrainAllLinearDof(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx
  hkpConstraintConstructionKit *v2; // rdi
  hkpGenericConstraintDataScheme *v3; // rax

  v1 = this->m_scheme;
  v2 = this;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 7;
  v3 = v2->m_scheme;
  v3->m_info.m_sizeOfSchemas += 144;
  v3->m_info.m_numSolverResults += 3;
  v3->m_info.m_numSolverElemTemps += 3;
}

// File Line: 91
// RVA: 0xD53670
__int64 __fastcall hkpConstraintConstructionKit::setAngularBasisA(hkpConstraintConstructionKit *this, hkMatrix3f *dofBasis)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkMatrix3f *v3; // rsi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int v6; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx
  hkpGenericConstraintDataScheme *v9; // rbx
  __int64 result; // rax

  v2 = this->m_scheme;
  v3 = dofBasis;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 8;
  v5 = v4->m_scheme;
  v6 = v5->m_data.m_size;
  v7 = &v5->m_data;
  if ( v5->m_data.m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
  v7->m_data[v7->m_size++] = v3->m_col0;
  v8 = v4->m_scheme;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_data, 16);
  v8->m_data.m_data[v8->m_data.m_size++] = v3->m_col1;
  v9 = v4->m_scheme;
  if ( v9->m_data.m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_data, 16);
  result = v6;
  v9->m_data.m_data[v9->m_data.m_size++] = v3->m_col2;
  v4->m_angularBasisSpecifiedA.m_bool = 1;
  return result;
}

// File Line: 102
// RVA: 0xD537A0
__int64 __fastcall hkpConstraintConstructionKit::setAngularBasisB(hkpConstraintConstructionKit *this, hkMatrix3f *dofBasis)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkMatrix3f *v3; // rsi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int v6; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx
  hkpGenericConstraintDataScheme *v9; // rbx
  __int64 result; // rax

  v2 = this->m_scheme;
  v3 = dofBasis;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 9;
  v5 = v4->m_scheme;
  v6 = v5->m_data.m_size;
  v7 = &v5->m_data;
  if ( v5->m_data.m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
  v7->m_data[v7->m_size++] = v3->m_col0;
  v8 = v4->m_scheme;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_data, 16);
  v8->m_data.m_data[v8->m_data.m_size++] = v3->m_col1;
  v9 = v4->m_scheme;
  if ( v9->m_data.m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_data, 16);
  result = v6;
  v9->m_data.m_data[v9->m_data.m_size++] = v3->m_col2;
  v4->m_angularBasisSpecifiedB.m_bool = 1;
  return result;
}

// File Line: 113
// RVA: 0xD538D0
void __fastcall hkpConstraintConstructionKit::setAngularBasisABodyFrame(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx
  hkpConstraintConstructionKit *v2; // rdi

  v1 = this->m_scheme;
  v2 = this;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 10;
  v2->m_angularBasisSpecifiedA.m_bool = 1;
}

// File Line: 119
// RVA: 0xD53930
void __fastcall hkpConstraintConstructionKit::setAngularBasisBBodyFrame(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx
  hkpConstraintConstructionKit *v2; // rdi

  v1 = this->m_scheme;
  v2 = this;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 11;
  v2->m_angularBasisSpecifiedB.m_bool = 1;
}

// File Line: 127
// RVA: 0xD53990
void __fastcall hkpConstraintConstructionKit::constrainToAngularDof(hkpConstraintConstructionKit *this, int axis)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  int v3; // esi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rbx
  hkpGenericConstraintDataScheme *v6; // rax

  v2 = this->m_scheme;
  v3 = axis;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 12;
  v5 = v4->m_scheme;
  if ( v5->m_commands.m_size == (v5->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_commands, 4);
  v5->m_commands.m_data[v5->m_commands.m_size++] = v3;
  v6 = v4->m_scheme;
  v6->m_info.m_sizeOfSchemas += 96;
  v6->m_info.m_numSolverResults += 2;
  v6->m_info.m_numSolverElemTemps += 2;
}

// File Line: 137
// RVA: 0xD53A40
void __fastcall hkpConstraintConstructionKit::constrainAllAngularDof(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx
  hkpConstraintConstructionKit *v2; // rdi
  hkpGenericConstraintDataScheme *v3; // rax

  v1 = this->m_scheme;
  v2 = this;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 13;
  v3 = v2->m_scheme;
  v3->m_info.m_sizeOfSchemas += 144;
  v3->m_info.m_numSolverResults += 3;
  v3->m_info.m_numSolverElemTemps += 3;
}

// File Line: 147
// RVA: 0xD53AB0
__int64 __fastcall hkpConstraintConstructionKit::setPivotA(hkpConstraintConstructionKit *this, hkVector4f *pivot)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkVector4f *v3; // rsi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int v6; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  __int64 result; // rax

  v2 = this->m_scheme;
  v3 = pivot;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 1;
  v5 = v4->m_scheme;
  v6 = v5->m_data.m_size;
  v7 = &v5->m_data;
  if ( v5->m_data.m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
  result = v6;
  v7->m_data[v7->m_size++] = (hkVector4f)v3->m_quad;
  v4->m_pivotSpecifiedA.m_bool = 1;
  return result;
}

// File Line: 156
// RVA: 0xD53B70
__int64 __fastcall hkpConstraintConstructionKit::setPivotB(hkpConstraintConstructionKit *this, hkVector4f *pivot)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkVector4f *v3; // rsi
  hkpConstraintConstructionKit *v4; // rdi
  hkpGenericConstraintDataScheme *v5; // rax
  unsigned int v6; // ebp
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  __int64 result; // rax

  v2 = this->m_scheme;
  v3 = pivot;
  v4 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 2;
  v5 = v4->m_scheme;
  v6 = v5->m_data.m_size;
  v7 = &v5->m_data;
  if ( v5->m_data.m_size == (v5->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
  result = v6;
  v7->m_data[v7->m_size++] = (hkVector4f)v3->m_quad;
  v4->m_pivotSpecifiedB.m_bool = 1;
  return result;
}

// File Line: 165
// RVA: 0xD53C30
__int64 __fastcall hkpConstraintConstructionKit::setPivotsHelper(hkpConstraintConstructionKit *this, hkpRigidBody *bodyA, hkpRigidBody *bodyB, hkVector4f *pivot)
{
  hkVector4f v4; // xmm3
  hkVector4f v5; // xmm0
  hkpConstraintConstructionKit *v6; // rdi
  __m128 v7; // xmm1
  __m128 v8; // xmm4
  __m128 v9; // xmm2
  __m128 v10; // xmm6
  __m128 v11; // xmm5
  __m128 v12; // xmm0
  hkVector4f v13; // xmm3
  __m128 v14; // xmm1
  __m128 v15; // xmm0
  __m128 v16; // xmm5
  hkVector4f v17; // xmm4
  __m128 v18; // xmm1
  hkVector4f v19; // xmm0
  __m128 v20; // xmm1
  __m128 v21; // xmm2
  unsigned int v22; // ebx
  __int64 result; // rax
  hkVector4f pivota; // [rsp+20h] [rbp-38h]
  hkVector4f v25; // [rsp+30h] [rbp-28h]

  v4.m_quad = (__m128)bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v5.m_quad = (__m128)bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  v6 = this;
  v7 = _mm_unpacklo_ps(bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v5.m_quad);
  v8 = _mm_shuffle_ps(
         _mm_unpackhi_ps(bodyA->m_motion.m_motionState.m_transform.m_rotation.m_col0.m_quad, v5.m_quad),
         v4.m_quad,
         228);
  v9 = _mm_movelh_ps(v7, v4.m_quad);
  v10 = _mm_sub_ps(pivot->m_quad, bodyB->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v11 = _mm_sub_ps(pivot->m_quad, bodyA->m_motion.m_motionState.m_transform.m_translation.m_quad);
  v12 = _mm_shuffle_ps(_mm_movehl_ps(v9, v7), v4.m_quad, 212);
  v13.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col2;
  v14 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 85), v12);
  v15 = _mm_shuffle_ps(v11, v11, 0);
  v16 = _mm_mul_ps(_mm_shuffle_ps(v11, v11, 170), v8);
  v17.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col0;
  v18 = _mm_add_ps(v14, _mm_mul_ps(v15, v9));
  v19.m_quad = (__m128)bodyB->m_motion.m_motionState.m_transform.m_rotation.m_col1;
  pivota.m_quad = _mm_add_ps(v18, v16);
  v20 = _mm_unpacklo_ps(v17.m_quad, v19.m_quad);
  v21 = _mm_movelh_ps(v20, v13.m_quad);
  v25.m_quad = _mm_add_ps(
                 _mm_add_ps(
                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 85), _mm_shuffle_ps(_mm_movehl_ps(v21, v20), v13.m_quad, 212)),
                   _mm_mul_ps(_mm_shuffle_ps(v10, v10, 0), v21)),
                 _mm_mul_ps(
                   _mm_shuffle_ps(v10, v10, 170),
                   _mm_shuffle_ps(_mm_unpackhi_ps(v17.m_quad, v19.m_quad), v13.m_quad, 228)));
  v22 = hkpConstraintConstructionKit::setPivotA(this, &pivota);
  hkpConstraintConstructionKit::setPivotB(v6, &v25);
  result = v22;
  *(_WORD *)&v6->m_pivotSpecifiedA.m_bool = 257;
  return result;
}

// File Line: 183
// RVA: 0xD53D50
int hkpConstraintConstructionKit::setLinearLimit(...)
{
  hkpGenericConstraintDataScheme *v4; // rbx
  int v5; // esi
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int v10; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v13; // rcx

  v4 = this->m_scheme;
  LOBYTE(v5) = axis;
  v6 = this;
  if ( v4->m_commands.m_size == (v4->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_commands, 4);
  v5 = (unsigned __int8)v5;
  v4->m_commands.m_data[v4->m_commands.m_size++] = 16;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v5;
  v8 = v6->m_scheme;
  v9 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)min, (__m128)0i64), _mm_unpacklo_ps((__m128)max, (__m128)0i64));
  v10 = v8->m_data.m_size;
  v11 = &v8->m_data;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 16);
  result = v10;
  v11->m_data[v11->m_size++].m_quad = v9;
  v13 = v6->m_scheme;
  v13->m_info.m_sizeOfSchemas += 64;
  ++v13->m_info.m_numSolverResults;
  ++v13->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 197
// RVA: 0xD53E70
int hkpConstraintConstructionKit::setAngularLimit(...)
{
  hkpGenericConstraintDataScheme *v4; // rbx
  int v5; // esi
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int v10; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v11; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v13; // rcx

  v4 = this->m_scheme;
  LOBYTE(v5) = axis;
  v6 = this;
  if ( v4->m_commands.m_size == (v4->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v4->m_commands, 4);
  v5 = (unsigned __int8)v5;
  v4->m_commands.m_data[v4->m_commands.m_size++] = 17;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v5;
  v8 = v6->m_scheme;
  v9 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)min, (__m128)0i64), _mm_unpacklo_ps((__m128)max, (__m128)0i64));
  v10 = v8->m_data.m_size;
  v11 = &v8->m_data;
  if ( v8->m_data.m_size == (v8->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v11, 16);
  result = v10;
  v11->m_data[v11->m_size++].m_quad = v9;
  v13 = v6->m_scheme;
  v13->m_info.m_sizeOfSchemas += 48;
  ++v13->m_info.m_numSolverResults;
  ++v13->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 212
// RVA: 0xD53F90
__int64 __fastcall hkpConstraintConstructionKit::setConeLimit(hkpConstraintConstructionKit *this, int axis, float angle)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  int v4; // esi
  hkpConstraintConstructionKit *v5; // rdi
  hkpGenericConstraintDataScheme *v6; // rbx
  __m128i v7; // xmm6
  __m128 v8; // xmm9
  hkpGenericConstraintDataScheme *v9; // rax
  __m128 v10; // xmm2
  __m128i v11; // xmm8
  unsigned int v12; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v13; // rbx
  __m128i v14; // xmm6
  __m128 v15; // xmm1
  __m128 v16; // xmm5
  __m128 v17; // xmm4
  __m128 v18; // xmm2
  __m128 v19; // xmm6
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v21; // rcx

  v3 = this->m_scheme;
  LOBYTE(v4) = axis;
  v5 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v4 = (unsigned __int8)v4;
  v3->m_commands.m_data[v3->m_commands.m_size++] = 18;
  v6 = v5->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_commands, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = v4;
  v7 = _mm_load_si128((const __m128i *)_xmm);
  v8 = _mm_add_ps((__m128)LODWORD(angle), *(__m128 *)_xmm);
  v9 = v5->m_scheme;
  v10 = _mm_andnot_ps(*(__m128 *)_xmm, v8);
  v11 = _mm_add_epi32(v7, v7);
  v12 = v9->m_data.m_size;
  v13 = &v9->m_data;
  v14 = _mm_andnot_si128(v7, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(*(__m128 *)_xmm, v10)), v7));
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
  if ( v9->m_data.m_size == (v9->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v13, 16);
  result = v12;
  v13->m_data[v13->m_size++].m_quad = v19;
  v21 = v5->m_scheme;
  v21->m_info.m_sizeOfSchemas += 48;
  ++v21->m_info.m_numSolverResults;
  ++v21->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 227
// RVA: 0xD541D0
__int64 __fastcall hkpConstraintConstructionKit::setTwistLimit(hkpConstraintConstructionKit *this, int twistAxis, int planeAxis, float min, float max)
{
  hkpGenericConstraintDataScheme *v5; // rbx
  unsigned __int8 v6; // bp
  int v7; // esi
  hkpConstraintConstructionKit *v8; // rdi
  hkpGenericConstraintDataScheme *v9; // rbx
  hkpGenericConstraintDataScheme *v10; // rbx
  __m128i v11; // xmm3
  __m128 v12; // xmm2
  __m128i v13; // xmm7
  __m128i v14; // xmm5
  __m128 v15; // xmm4
  __m128 v16; // xmm0
  __m128 v17; // xmm3
  __m128 v18; // xmm2
  unsigned int v19; // ST20_4
  __m128 v20; // xmm2
  __m128i v21; // xmm0
  __m128i v22; // xmm0
  __m128 v23; // xmm1
  hkpGenericConstraintDataScheme *v24; // rax
  unsigned int v25; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v26; // rbx
  __m128 v27; // xmm5
  __m128 v28; // xmm4
  __m128 v29; // xmm2
  __m128 v30; // xmm6
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v32; // rcx
  __int128 v33; // [rsp+30h] [rbp-48h]
  __m128i v34; // [rsp+40h] [rbp-38h]
  float v35; // [rsp+98h] [rbp+20h]

  v35 = min;
  v5 = this->m_scheme;
  v6 = planeAxis;
  LOBYTE(v7) = twistAxis;
  v8 = this;
  if ( v5->m_commands.m_size == (v5->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v5->m_commands, 4);
  v7 = (unsigned __int8)v7;
  v5->m_commands.m_data[v5->m_commands.m_size++] = 19;
  v9 = v8->m_scheme;
  if ( v9->m_commands.m_size == (v9->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v9->m_commands, 4);
  v9->m_commands.m_data[v9->m_commands.m_size++] = v7;
  v10 = v8->m_scheme;
  if ( v10->m_commands.m_size == (v10->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v10->m_commands, 4);
  v10->m_commands.m_data[v10->m_commands.m_size++] = v6;
  v11 = _mm_load_si128((const __m128i *)_xmm);
  v12 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(max));
  v13 = _mm_add_epi32(v11, v11);
  _mm_store_si128((__m128i *)&v33, v13);
  v14 = _mm_andnot_si128(v11, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v12, *(__m128 *)_xmm)), v11));
  v15 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v14, v13), (__m128i)0i64);
  v16 = _mm_cvtepi32_ps(v14);
  v17 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v16, *(__m128 *)DP1_0), v12), _mm_mul_ps(v16, *(__m128 *)DP2)),
          _mm_mul_ps(v16, *(__m128 *)DP3));
  v18 = _mm_mul_ps(v17, v17);
  v19 = (*(unsigned __int128 *)&_mm_andnot_ps(
                                  v15,
                                  _mm_add_ps(
                                    _mm_sub_ps(
                                      _mm_mul_ps(
                                        _mm_mul_ps(
                                          _mm_add_ps(
                                            _mm_mul_ps(
                                              _mm_add_ps(_mm_mul_ps(v18, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1),
                                              v18),
                                            *(__m128 *)cosCoeff2_0),
                                          v18),
                                        v18),
                                      _mm_mul_ps(v18, *(__m128 *)_xmm)),
                                    *(__m128 *)_xmm)) | COERCE_UNSIGNED_INT(
                                                          (float)((float)((float)((float)((float)((float)(v18.m128_f32[0] * -0.00019515296)
                                                                                                + 0.0083321612)
                                                                                        * v18.m128_f32[0])
                                                                                + -0.16666655)
                                                                        * v18.m128_f32[0])
                                                                * v17.m128_f32[0])
                                                        + v17.m128_f32[0]) & v15.m128_i32[0]) ^ ((unsigned int)*(_OWORD *)&_mm_and_si128(_mm_add_epi32(v13, v13), v14) << 29) ^ LODWORD(max) & _xmm[0];
  v20 = _mm_andnot_ps(*(__m128 *)_xmm, (__m128)LODWORD(v35));
  v21 = _mm_load_si128((const __m128i *)_xmm);
  v22 = _mm_andnot_si128(v21, _mm_add_epi32(_mm_cvttps_epi32(_mm_mul_ps(v20, *(__m128 *)_xmm)), v21));
  v23 = _mm_cvtepi32_ps(v22);
  _mm_store_si128(&v34, v22);
  v24 = v8->m_scheme;
  v25 = v24->m_data.m_size;
  v26 = &v24->m_data;
  v27 = (__m128)_mm_cmpeq_epi32(_mm_and_si128(v22, v13), (__m128i)0i64);
  v28 = _mm_add_ps(
          _mm_add_ps(_mm_add_ps(_mm_mul_ps(v23, *(__m128 *)DP1_0), v20), _mm_mul_ps(v23, *(__m128 *)DP2)),
          _mm_mul_ps(v23, *(__m128 *)DP3));
  v29 = _mm_mul_ps(v28, v28);
  v30 = _mm_unpacklo_ps(
          _mm_unpacklo_ps(
            _mm_xor_ps(
              _mm_xor_ps(
                _mm_and_ps((__m128)LODWORD(v35), *(__m128 *)_xmm),
                (__m128)_mm_slli_epi32(_mm_and_si128(_mm_add_epi32(v13, v13), v34), 0x1Du)),
              _mm_or_ps(
                _mm_andnot_ps(
                  v27,
                  _mm_add_ps(
                    _mm_sub_ps(
                      _mm_mul_ps(
                        _mm_mul_ps(
                          _mm_add_ps(
                            _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v29, *(__m128 *)cosCoeff0_0), *(__m128 *)cosCoeff1), v29),
                            *(__m128 *)cosCoeff2_0),
                          v29),
                        v29),
                      _mm_mul_ps(v29, *(__m128 *)_xmm)),
                    *(__m128 *)_xmm)),
                _mm_and_ps(
                  _mm_add_ps(
                    _mm_mul_ps(
                      _mm_mul_ps(
                        _mm_add_ps(
                          _mm_mul_ps(_mm_add_ps(_mm_mul_ps(v29, *(__m128 *)sinCoeff0), *(__m128 *)sinCoeff1_0), v29),
                          *(__m128 *)sinCoeff2_0),
                        v29),
                      v28),
                    v28),
                  v27))),
            (__m128)0i64),
          _mm_unpacklo_ps((__m128)v19, (__m128)0i64));
  if ( v24->m_data.m_size == (v24->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v26, 16);
  result = v25;
  v26->m_data[v26->m_size++].m_quad = v30;
  v32 = v8->m_scheme;
  v32->m_info.m_sizeOfSchemas += 48;
  ++v32->m_info.m_numSolverResults;
  ++v32->m_info.m_numSolverElemTemps;
  return result;
}

// File Line: 245
// RVA: 0xD54560
__int64 __fastcall hkpConstraintConstructionKit::setAngularMotor(hkpConstraintConstructionKit *this, int axis, hkpConstraintMotor *motor)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  hkpConstraintMotor *v4; // rsi
  int v5; // ebp
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int v10; // ebp
  __m128 v11; // xmm6
  hkpGenericConstraintDataScheme *v12; // rbx
  hkpGenericConstraintDataScheme *v13; // rbx
  hkpGenericConstraintDataScheme *v14; // rcx

  v3 = this->m_scheme;
  v4 = motor;
  LOBYTE(v5) = axis;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v5 = (unsigned __int8)v5;
  v3->m_commands.m_data[v3->m_commands.m_size++] = 14;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v5;
  v8 = v6->m_scheme;
  v9 = 0i64;
  v10 = v8->m_data.m_size;
  v9.m128_f32[0] = (float)v8->m_motors.m_size;
  v11 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)0i64),
          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v12 = v6->m_scheme;
  if ( v12->m_data.m_size == (v12->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v12->m_data, 16);
  v12->m_data.m_data[v12->m_data.m_size++].m_quad = v11;
  v13 = v6->m_scheme;
  if ( v13->m_motors.m_size == (v13->m_motors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v13->m_motors, 8);
  v13->m_motors.m_data[v13->m_motors.m_size++] = v4;
  v14 = v6->m_scheme;
  v14->m_info.m_sizeOfSchemas += 64;
  v14->m_info.m_numSolverResults += 2;
  v14->m_info.m_numSolverElemTemps += 2;
  return v10;
}

// File Line: 266
// RVA: 0xD546C0
__int64 __fastcall hkpConstraintConstructionKit::setLinearMotor(hkpConstraintConstructionKit *this, int axis, hkpConstraintMotor *motor)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  hkpConstraintMotor *v4; // rsi
  int v5; // ebp
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rax
  __m128 v9; // xmm6
  unsigned int v10; // ebp
  __m128 v11; // xmm6
  hkpGenericConstraintDataScheme *v12; // rbx
  hkpGenericConstraintDataScheme *v13; // rbx
  hkpGenericConstraintDataScheme *v14; // rcx

  v3 = this->m_scheme;
  v4 = motor;
  LOBYTE(v5) = axis;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v5 = (unsigned __int8)v5;
  v3->m_commands.m_data[v3->m_commands.m_size++] = 15;
  v7 = v6->m_scheme;
  if ( v7->m_commands.m_size == (v7->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_commands, 4);
  v7->m_commands.m_data[v7->m_commands.m_size++] = v5;
  v8 = v6->m_scheme;
  v9 = 0i64;
  v10 = v8->m_data.m_size;
  v9.m128_f32[0] = (float)v8->m_motors.m_size;
  v11 = _mm_movelh_ps(
          _mm_unpacklo_ps(_mm_shuffle_ps(v9, v9, 0), (__m128)0i64),
          _mm_unpacklo_ps((__m128)0i64, (__m128)0i64));
  hkReferencedObject::addReference((hkReferencedObject *)&v4->vfptr);
  v12 = v6->m_scheme;
  if ( v12->m_data.m_size == (v12->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v12->m_data, 16);
  v12->m_data.m_data[v12->m_data.m_size++].m_quad = v11;
  v13 = v6->m_scheme;
  if ( v13->m_motors.m_size == (v13->m_motors.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v13->m_motors, 8);
  v13->m_motors.m_data[v13->m_motors.m_size++] = v4;
  v14 = v6->m_scheme;
  v14->m_info.m_sizeOfSchemas += 80;
  v14->m_info.m_numSolverResults += 2;
  v14->m_info.m_numSolverElemTemps += 2;
  return v10;
}

// File Line: 288
// RVA: 0xD54820
int hkpConstraintConstructionKit::setAngularFriction(...)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  int v4; // esi
  hkpConstraintConstructionKit *v5; // rdi
  hkpGenericConstraintDataScheme *v6; // rbx
  hkpGenericConstraintDataScheme *v7; // rax
  __m128 v8; // xmm6
  unsigned int v9; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v12; // rcx

  v3 = this->m_scheme;
  LOBYTE(v4) = axis;
  v5 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v4 = (unsigned __int8)v4;
  v3->m_commands.m_data[v3->m_commands.m_size++] = 20;
  v6 = v5->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_commands, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = v4;
  v7 = v5->m_scheme;
  v8 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)maxImpulse, (__m128)0i64), (__m128)0i64);
  v9 = v7->m_data.m_size;
  v10 = &v7->m_data;
  if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
  result = v9;
  v10->m_data[v10->m_size++].m_quad = v8;
  v12 = v5->m_scheme;
  v12->m_info.m_sizeOfSchemas += 48;
  v12->m_info.m_numSolverResults += 2;
  v12->m_info.m_numSolverElemTemps += 2;
  return result;
}

// File Line: 301
// RVA: 0xD54930
int hkpConstraintConstructionKit::setLinearFriction(...)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  int v4; // esi
  hkpConstraintConstructionKit *v5; // rdi
  hkpGenericConstraintDataScheme *v6; // rbx
  hkpGenericConstraintDataScheme *v7; // rax
  __m128 v8; // xmm6
  unsigned int v9; // esi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v10; // rbx
  __int64 result; // rax
  hkpGenericConstraintDataScheme *v12; // rcx

  v3 = this->m_scheme;
  LOBYTE(v4) = axis;
  v5 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v4 = (unsigned __int8)v4;
  v3->m_commands.m_data[v3->m_commands.m_size++] = 21;
  v6 = v5->m_scheme;
  if ( v6->m_commands.m_size == (v6->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v6->m_commands, 4);
  v6->m_commands.m_data[v6->m_commands.m_size++] = v4;
  v7 = v5->m_scheme;
  v8 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)maxImpulse, (__m128)0i64), (__m128)0i64);
  v9 = v7->m_data.m_size;
  v10 = &v7->m_data;
  if ( v7->m_data.m_size == (v7->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v10, 16);
  result = v9;
  v10->m_data[v10->m_size++].m_quad = v8;
  v12 = v5->m_scheme;
  v12->m_info.m_sizeOfSchemas += 64;
  v12->m_info.m_numSolverResults += 2;
  v12->m_info.m_numSolverElemTemps += 2;
  return result;
}

// File Line: 319
// RVA: 0xD54A40
int hkpConstraintConstructionKit::setStrength(...)
{
  hkpGenericConstraintDataScheme *v2; // rbx
  hkpConstraintConstructionKit *v3; // rdi
  hkpGenericConstraintDataScheme *v4; // rax
  __m128 v5; // xmm6
  unsigned int v6; // edi
  hkArray<hkVector4f,hkContainerHeapAllocator> *v7; // rbx
  __int64 result; // rax

  v2 = this->m_scheme;
  ++this->m_stiffnessReference;
  v3 = this;
  if ( v2->m_commands.m_size == (v2->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v2->m_commands, 4);
  v2->m_commands.m_data[v2->m_commands.m_size++] = 22;
  v4 = v3->m_scheme;
  v5 = _mm_unpacklo_ps(_mm_unpacklo_ps((__m128)strength, (__m128)0i64), (__m128)0i64);
  v6 = v4->m_data.m_size;
  v7 = &v4->m_data;
  if ( v4->m_data.m_size == (v4->m_data.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, v7, 16);
  result = v6;
  v7->m_data[v7->m_size++].m_quad = v5;
  return result;
}

// File Line: 331
// RVA: 0xD54B00
void __fastcall hkpConstraintConstructionKit::restoreStrength(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx

  v1 = this->m_scheme;
  --this->m_stiffnessReference;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 23;
}

// File Line: 339
// RVA: 0xD54B50
void __fastcall hkpConstraintConstructionKit::addConstraintModifierCallback(hkpConstraintConstructionKit *this, hkpConstraintModifier *cm, int userData)
{
  hkpGenericConstraintDataScheme *v3; // rbx
  int v4; // esi
  hkpConstraintModifier *v5; // rbp
  hkpConstraintConstructionKit *v6; // rdi
  hkpGenericConstraintDataScheme *v7; // rbx
  hkpGenericConstraintDataScheme *v8; // rbx

  v3 = this->m_scheme;
  v4 = userData;
  v5 = cm;
  v6 = this;
  if ( v3->m_commands.m_size == (v3->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v3->m_commands, 4);
  v3->m_commands.m_data[v3->m_commands.m_size++] = 24;
  v7 = v6->m_scheme;
  if ( v7->m_modifiers.m_size == (v7->m_modifiers.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v7->m_modifiers, 8);
  v7->m_modifiers.m_data[v7->m_modifiers.m_size++] = v5;
  v8 = v6->m_scheme;
  if ( v8->m_commands.m_size == (v8->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v8->m_commands, 4);
  v8->m_commands.m_data[v8->m_commands.m_size++] = v4;
}

// File Line: 348
// RVA: 0xD54C30
void __fastcall hkpConstraintConstructionKit::end(hkpConstraintConstructionKit *this)
{
  hkpGenericConstraintDataScheme *v1; // rbx

  v1 = this->m_scheme;
  if ( v1->m_commands.m_size == (v1->m_commands.m_capacityAndFlags & 0x3FFFFFFF) )
    hkArrayUtil::_reserveMore((hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr, &v1->m_commands, 4);
  v1->m_commands.m_data[v1->m_commands.m_size++] = 0;
}

// File Line: 356
// RVA: 0xD54C80
void __fastcall hkpConstraintConstructionKit::computeConstraintInfo(hkArray<int,hkContainerHeapAllocator> *commands, hkpConstraintInfo *info)
{
  int *v2; // r8
  int *v3; // r9

  v2 = commands->m_data;
  v3 = &commands->m_data[commands->m_size];
  if ( commands->m_data < v3 )
  {
    do
    {
      switch ( *v2 )
      {
        case 0:
          return;
        case 3:
        case 4:
        case 5:
        case 24:
          ++v2;
          break;
        case 6:
        case 17:
        case 18:
          info->m_sizeOfSchemas += 48;
          ++info->m_numSolverResults;
          ++v2;
          ++info->m_numSolverElemTemps;
          break;
        case 7:
        case 13:
          info->m_sizeOfSchemas += 144;
          info->m_numSolverResults += 3;
          info->m_numSolverElemTemps += 3;
          break;
        case 12:
          info->m_sizeOfSchemas += 96;
          info->m_numSolverResults += 2;
          ++v2;
          info->m_numSolverElemTemps += 2;
          break;
        case 14:
        case 21:
          info->m_sizeOfSchemas += 64;
          info->m_numSolverResults += 2;
          ++v2;
          info->m_numSolverElemTemps += 2;
          break;
        case 15:
          info->m_sizeOfSchemas += 80;
          info->m_numSolverResults += 2;
          ++v2;
          info->m_numSolverElemTemps += 2;
          break;
        case 16:
          info->m_sizeOfSchemas += 64;
          ++info->m_numSolverResults;
          ++v2;
          ++info->m_numSolverElemTemps;
          break;
        case 19:
          info->m_sizeOfSchemas += 48;
          ++info->m_numSolverResults;
          v2 += 2;
          ++info->m_numSolverElemTemps;
          break;
        case 20:
          info->m_sizeOfSchemas += 48;
          info->m_numSolverResults += 2;
          ++v2;
          info->m_numSolverElemTemps += 2;
          break;
        default:
          break;
      }
      ++v2;
    }
    while ( v2 < v3 );
  }
}

