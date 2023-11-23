// File Line: 71
// RVA: 0x399700
void __fastcall UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(
        UFG::qPropertySet **array,
        int size,
        bool (__fastcall *predicate)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))
{
  __int64 v3; // rbp
  __int64 v4; // r12
  int v7; // r14d
  UFG::qPropertySet *v8; // rax
  int v9; // ebx
  __int64 v10; // rdi
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // [rsp+68h] [rbp+20h] BYREF

  v3 = 1i64;
  v4 = size;
  if ( size > 1i64 )
  {
    v7 = 0;
    do
    {
      v8 = array[v3];
      v9 = v7;
      v10 = v3 - 1;
      v12 = v8;
      if ( v7 >= 0 )
      {
        do
        {
          if ( !predicate(&v12, &array[v9]) )
            break;
          v11 = array[v10--];
          --v9;
          array[v10 + 2] = v11;
        }
        while ( v9 >= 0 );
        v8 = v12;
      }
      ++v3;
      ++v7;
      array[v10 + 1] = v8;
    }
    while ( v3 < v4 );
  }
}

// File Line: 162
// RVA: 0x435BF0
void __fastcall UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(
        Render::IrradianceVolume **left,
        Render::IrradianceVolume **right,
        bool (__fastcall *predicate)(Render::IrradianceVolume *, Render::IrradianceVolume *))
{
  Render::IrradianceVolume **v4; // rbp
  Render::IrradianceVolume **v5; // rdi
  int v6; // eax
  Render::IrradianceVolume **v7; // rbx
  Render::IrradianceVolume *v8; // rcx
  Render::IrradianceVolume *v9; // rcx
  Render::IrradianceVolume *v10; // rcx
  Render::IrradianceVolume **v11; // rax
  Render::IrradianceVolume *v12; // rbp
  unsigned __int64 v13; // rbx
  Render::IrradianceVolume **v14; // rdi
  Render::IrradianceVolume *v15; // rcx
  Render::IrradianceVolume *v16; // rdx
  Render::IrradianceVolume *v17; // rax
  Render::IrradianceVolume *v18; // rcx
  Render::IrradianceVolume **v19; // [rsp+20h] [rbp-28h]
  Render::IrradianceVolume **lefta; // [rsp+50h] [rbp+8h]
  unsigned __int64 v22; // [rsp+68h] [rbp+20h]

  lefta = left;
  v4 = right;
  v5 = left;
  v6 = right - left + 1;
  if ( v6 < 32 )
  {
LABEL_24:
    if ( v6 > 1 )
      UFG::qInsertionSort<UFG::ResourceRequest *,bool (*)(UFG::ResourceRequest const *,UFG::ResourceRequest const *)>(
        v5,
        v6,
        predicate);
  }
  else
  {
    while ( 1 )
    {
      v7 = &v5[(v4 - v5) / 2];
      if ( predicate(*v7, *v5) )
      {
        v8 = *v7;
        *v7 = *v5;
        *v5 = v8;
      }
      if ( predicate(*v4, *v7) )
      {
        v9 = *v4;
        *v4 = *v7;
        *v7 = v9;
      }
      if ( predicate(*v7, *v5) )
      {
        v10 = *v7;
        *v7 = *v5;
        *v5 = v10;
      }
      v11 = lefta;
      v12 = *v7;
      v13 = (unsigned __int64)v5;
      v19 = right;
      v14 = right;
      v22 = v13;
      if ( lefta <= right )
      {
        do
        {
          if ( predicate(*(Render::IrradianceVolume **)v13, v12) )
          {
            do
            {
              if ( v13 >= (unsigned __int64)right )
                break;
              v15 = *(Render::IrradianceVolume **)(v13 + 8);
              v13 += 8i64;
            }
            while ( predicate(v15, v12) );
            v14 = v19;
            v22 = v13;
          }
          if ( predicate(v12, *v14) )
          {
            do
            {
              if ( lefta >= v14 )
                break;
              v16 = *--v14;
            }
            while ( predicate(v12, v16) );
            v13 = v22;
          }
          if ( v13 > (unsigned __int64)v14 )
            break;
          v17 = *v14;
          v18 = *(Render::IrradianceVolume **)v13;
          --v14;
          *(_QWORD *)v13 = v17;
          v13 += 8i64;
          v14[1] = v18;
          v22 = v13;
          v19 = v14;
        }
        while ( v13 <= (unsigned __int64)v14 );
        v11 = lefta;
      }
      if ( v11 < v14 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(v11, v14, predicate);
      v4 = right;
      if ( v13 >= (unsigned __int64)right )
        break;
      v5 = (Render::IrradianceVolume **)v13;
      lefta = (Render::IrradianceVolume **)v13;
      v6 = ((__int64)((__int64)right - v13) >> 3) + 1;
      if ( v6 < 32 )
        goto LABEL_24;
    }
  }
}

// File Line: 219
// RVA: 0x1EBEB0
void __fastcall UFG::qQuickSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
        UFG::PropertyLookup *array,
        int size,
        bool (__fastcall *predicate)(UFG::PropertyLookup *, UFG::PropertyLookup *))
{
  UFG::qQuickSortImpl<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
    array,
    &array[size - 1],
    predicate);
}

// File Line: 240
// RVA: 0x1ECB50
void __fastcall UFG::qSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
        UFG::PropertyLookup *array,
        int size,
        bool (__fastcall *predicate)(UFG::PropertyLookup *, UFG::PropertyLookup *))
{
  UFG::qQuickSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
    array,
    size,
    predicate);
}

