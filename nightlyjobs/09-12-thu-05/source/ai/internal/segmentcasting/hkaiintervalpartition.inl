// File Line: 11
// RVA: 0x12E35F0
void __fastcall hkaiIntervalPartition::filterIntervals<`anonymous namespace'::ContractFilter>(hkaiIntervalPartition *this, ContractFilter *filter)
{
  signed __int64 v2; // rdi
  int v3; // er11
  ContractFilter *v4; // rbx
  hkaiIntervalPartition *v5; // r10
  signed __int64 v6; // r14
  __int64 v7; // rdx
  __int64 v8; // r9
  __int64 v9; // r8
  unsigned __int64 v10; // rsi
  hkaiIntervalPartition::Interval *v11; // rax
  float v12; // xmm1_4
  hkaiIntervalPartition::Interval *v13; // rcx
  hkaiIntervalPartition::Interval *v14; // rax
  float v15; // xmm1_4
  hkaiIntervalPartition::Interval *v16; // rcx
  hkaiIntervalPartition::Interval *v17; // rax
  float v18; // xmm1_4
  hkaiIntervalPartition::Interval *v19; // rcx
  hkaiIntervalPartition::Interval *v20; // rax
  float v21; // xmm1_4
  hkaiIntervalPartition::Interval *v22; // rcx
  signed __int64 v23; // r8
  signed __int64 v24; // rdx
  signed __int64 v25; // r8
  signed __int64 v26; // rdi
  hkaiIntervalPartition::Interval *v27; // rax
  float v28; // xmm0_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  hkaiIntervalPartition::Interval *v31; // rcx

  v2 = this->m_intervals.m_size;
  v3 = 0;
  v4 = filter;
  v5 = this;
  v6 = 0i64;
  v7 = 0i64;
  if ( v2 >= 4 )
  {
    v8 = 0i64;
    v9 = 0i64;
    v10 = ((unsigned __int64)(v2 - 4) >> 2) + 1;
    v6 = 4 * v10;
    do
    {
      v11 = v5->m_intervals.m_data;
      v11[v9].m_leftX = v5->m_intervals.m_data[v9].m_leftX + v4->m_maxContract;
      v12 = v11[v9].m_rightX - v4->m_maxContract;
      v11[v9].m_rightX = v12;
      if ( v12 > v11[v9].m_leftX )
      {
        v13 = v5->m_intervals.m_data;
        ++v3;
        ++v7;
        ++v8;
        v13[v8 - 1].m_leftX = v5->m_intervals.m_data[v9].m_leftX;
        *((_DWORD *)&v13[v8] - 4) = LODWORD(v13[v9].m_rightX);
        *((_DWORD *)&v13[v8] - 3) = LODWORD(v13[v9].m_slope);
        *((_DWORD *)&v13[v8] - 2) = LODWORD(v13[v9].m_offset);
        *((_DWORD *)&v13[v8] - 1) = v13[v9].m_data;
      }
      v14 = v5->m_intervals.m_data;
      v14[v9 + 1].m_leftX = v5->m_intervals.m_data[v9 + 1].m_leftX + v4->m_maxContract;
      v15 = v14[v9 + 1].m_rightX - v4->m_maxContract;
      v14[v9 + 1].m_rightX = v15;
      if ( v15 > v14[v9 + 1].m_leftX )
      {
        v16 = v5->m_intervals.m_data;
        ++v3;
        ++v7;
        ++v8;
        v16[v8 - 1].m_leftX = v5->m_intervals.m_data[v9 + 1].m_leftX;
        *((_DWORD *)&v16[v8] - 4) = LODWORD(v16[v9 + 1].m_rightX);
        *((_DWORD *)&v16[v8] - 3) = LODWORD(v16[v9 + 1].m_slope);
        *((_DWORD *)&v16[v8] - 2) = LODWORD(v16[v9 + 1].m_offset);
        *((_DWORD *)&v16[v8] - 1) = v16[v9 + 1].m_data;
      }
      v17 = v5->m_intervals.m_data;
      v17[v9 + 2].m_leftX = v5->m_intervals.m_data[v9 + 2].m_leftX + v4->m_maxContract;
      v18 = v17[v9 + 2].m_rightX - v4->m_maxContract;
      v17[v9 + 2].m_rightX = v18;
      if ( v18 > v17[v9 + 2].m_leftX )
      {
        v19 = v5->m_intervals.m_data;
        ++v3;
        ++v7;
        ++v8;
        v19[v8 - 1].m_leftX = v5->m_intervals.m_data[v9 + 2].m_leftX;
        *((_DWORD *)&v19[v8] - 4) = LODWORD(v19[v9 + 2].m_rightX);
        *((_DWORD *)&v19[v8] - 3) = LODWORD(v19[v9 + 2].m_slope);
        *((_DWORD *)&v19[v8] - 2) = LODWORD(v19[v9 + 2].m_offset);
        *((_DWORD *)&v19[v8] - 1) = v19[v9 + 2].m_data;
      }
      v20 = v5->m_intervals.m_data;
      v20[v9 + 3].m_leftX = v5->m_intervals.m_data[v9 + 3].m_leftX + v4->m_maxContract;
      v21 = v20[v9 + 3].m_rightX - v4->m_maxContract;
      v20[v9 + 3].m_rightX = v21;
      if ( v21 > v20[v9 + 3].m_leftX )
      {
        v22 = v5->m_intervals.m_data;
        ++v3;
        ++v7;
        ++v8;
        v22[v8 - 1].m_leftX = v5->m_intervals.m_data[v9 + 3].m_leftX;
        *((_DWORD *)&v22[v8] - 4) = LODWORD(v22[v9 + 3].m_rightX);
        *((_DWORD *)&v22[v8] - 3) = LODWORD(v22[v9 + 3].m_slope);
        *((_DWORD *)&v22[v8] - 2) = LODWORD(v22[v9 + 3].m_offset);
        *((_DWORD *)&v22[v8] - 1) = v22[v9 + 3].m_data;
      }
      v9 += 4i64;
      --v10;
    }
    while ( v10 );
  }
  if ( v6 < v2 )
  {
    v23 = 5 * v7;
    v24 = v6;
    v25 = 4 * v23;
    v26 = v2 - v6;
    do
    {
      v27 = v5->m_intervals.m_data;
      v28 = v5->m_intervals.m_data[v24].m_rightX;
      v29 = v5->m_intervals.m_data[v24].m_leftX + v4->m_maxContract;
      v27[v24].m_leftX = v29;
      v30 = v28 - v4->m_maxContract;
      v27[v24].m_rightX = v30;
      if ( v30 > v29 )
      {
        v31 = v5->m_intervals.m_data;
        ++v3;
        v25 += 20i64;
        *(float *)((char *)&v31[-1].m_leftX + v25) = v5->m_intervals.m_data[v24].m_leftX;
        *(float *)((char *)v31 + v25 - 16) = v31[v24].m_rightX;
        *(float *)((char *)v31 + v25 - 12) = v31[v24].m_slope;
        *(float *)((char *)v31 + v25 - 8) = v31[v24].m_offset;
        *(_DWORD *)((char *)v31 + v25 - 4) = v31[v24].m_data;
      }
      ++v24;
      --v26;
    }
    while ( v26 );
  }
  v5->m_intervals.m_size = v3;
}

