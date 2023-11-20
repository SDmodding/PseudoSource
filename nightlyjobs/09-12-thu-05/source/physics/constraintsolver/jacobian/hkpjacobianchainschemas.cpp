// File Line: 16
// RVA: 0x132A900
hkpJacobianSchema *__fastcall hkJacobianStiffSpringChainSchema_getJacobians(hkpJacobianSchema *schema)
{
  return schema + 32;
}

// File Line: 17
// RVA: 0x132A910
hkpJacobianSchema *__fastcall hkJacobianBallSocketChainSchema_getJacobians(hkpJacobianSchema *schema)
{
  return schema + 32;
}

// File Line: 18
// RVA: 0x132A920
hkpJacobianSchema *__fastcall hkJacobianStabilizedBallSocketChainSchema_getJacobians(hkpJacobianSchema *schema)
{
  return schema + 32;
}

// File Line: 19
// RVA: 0x132A9D0
hkpJacobianSchema *__fastcall hkJacobianPoweredChainSchema_getLinearJacobians(hkpJacobianSchema *schema)
{
  return schema + 32;
}

// File Line: 20
// RVA: 0x132A9E0
hkpJacobianSchema *__fastcall hkJacobianPoweredChainSchema_getAngularJacobians(hkpJacobianSchema *schema, int numConstraints)
{
  return &schema[144 * numConstraints + 32];
}

// File Line: 24
// RVA: 0x132A930
hkpJacobianSchema *__fastcall hkJacobianStabilizedBallSocketChainSchema_init(hkpJacobianSchema *sIn, int numConstraints, hkpVelocityAccumulatorOffset *accumulatorsIn, float tau, float damping, float cfm, float virtualMassFactor)
{
  hkpJacobianSchema *v7; // r11
  int v8; // er10
  signed __int64 v9; // r9
  __int64 v10; // rcx
  unsigned int v11; // eax

  v7 = sIn;
  *(_WORD *)&sIn[4] = numConstraints;
  v8 = (unsigned __int16)numConstraints + 1;
  *(float *)&sIn[16] = damping;
  *(float *)&sIn[12] = tau;
  *(float *)&sIn[20] = cfm;
  *(float *)&sIn[24] = virtualMassFactor;
  *(_DWORD *)&sIn[8] = (((unsigned __int16)numConstraints << 6) + 20 * v8 + 47) & 0xFFFFFFF0;
  if ( numConstraints + 1 > 0 )
  {
    v9 = 16 * (v8 + 4i64 * (unsigned __int16)numConstraints + 2) - (_QWORD)accumulatorsIn;
    v10 = (unsigned int)(numConstraints + 1);
    do
    {
      v11 = accumulatorsIn->m_offset;
      ++accumulatorsIn;
      *(_DWORD *)&v7[v9 - 4 + (_QWORD)accumulatorsIn] = v11;
      --v10;
    }
    while ( v10 );
  }
  return v7 + 32;
}

