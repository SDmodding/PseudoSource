// File Line: 71
// RVA: 0x399700
void __fastcall UFG::qInsertionSort<UFG::OSuiteLeaderboardData const *,bool (*)(UFG::OSuiteLeaderboardData const * const &,UFG::OSuiteLeaderboardData const * const &)>(UFG::qPropertySet **array, int size, bool (__fastcall *predicate)(UFG::qPropertySet *const *, UFG::qPropertySet *const *))
{
  signed __int64 v3; // rbp
  signed __int64 v4; // r12
  bool (__fastcall *v5)(UFG::qPropertySet *const *, UFG::qPropertySet *const *); // r15
  UFG::qPropertySet **v6; // rsi
  int v7; // er14
  __int64 v8; // rax
  int v9; // ebx
  signed __int64 v10; // rdi
  UFG::qPropertySet *v11; // rax
  UFG::qPropertySet *v12; // [rsp+68h] [rbp+20h]

  v3 = 1i64;
  v4 = size;
  v5 = predicate;
  v6 = array;
  if ( size > 1i64 )
  {
    v7 = 0;
    do
    {
      v8 = (__int64)v6[v3];
      v9 = v7;
      v10 = v3 - 1;
      v12 = v6[v3];
      if ( v7 >= 0 )
      {
        do
        {
          if ( !v5(&v12, &v6[v9]) )
            break;
          v11 = v6[v10--];
          --v9;
          v6[v10 + 2] = v11;
        }
        while ( v9 >= 0 );
        v8 = (__int64)v12;
      }
      ++v3;
      ++v7;
      v6[v10 + 1] = (UFG::qPropertySet *)v8;
    }
    while ( v3 < v4 );
  }
}

// File Line: 162
// RVA: 0x435BF0
void __fastcall UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(Render::IrradianceVolume **left, Render::IrradianceVolume **right, bool (__fastcall *predicate)(Render::IrradianceVolume *, Render::IrradianceVolume *))
{
  bool (__fastcall *v3)(Render::IrradianceVolume *, Render::IrradianceVolume *); // rsi
  Render::IrradianceVolume **v4; // rbp
  Render::IrradianceVolume **v5; // rdi
  int v6; // eax
  Render::IrradianceVolume **v7; // rbx
  Render::IrradianceVolume *v8; // rcx
  Render::IrradianceVolume *v9; // rcx
  Render::IrradianceVolume *v10; // rcx
  Render::IrradianceVolume **v11; // rax
  Render::IrradianceVolume *v12; // rbp
  Render::IrradianceVolume **v13; // rbx
  Render::IrradianceVolume **v14; // rdi
  Render::IrradianceVolume *v15; // rcx
  Render::IrradianceVolume *v16; // rdx
  Render::IrradianceVolume *v17; // rax
  Render::IrradianceVolume *v18; // rcx
  Render::IrradianceVolume **v19; // [rsp+20h] [rbp-28h]
  Render::IrradianceVolume **lefta; // [rsp+50h] [rbp+8h]
  Render::IrradianceVolume **righta; // [rsp+58h] [rbp+10h]
  Render::IrradianceVolume **v22; // [rsp+68h] [rbp+20h]

  righta = right;
  lefta = left;
  v3 = predicate;
  v4 = right;
  v5 = left;
  v6 = (unsigned __int64)(right - left) + 1;
  if ( v6 < 32 )
  {
LABEL_24:
    if ( v6 > 1 )
      UFG::qInsertionSort<UFG::ResourceRequest *,bool (*)(UFG::ResourceRequest const *,UFG::ResourceRequest const *)>(
        v5,
        v6,
        v3);
  }
  else
  {
    while ( 1 )
    {
      v7 = &v5[(v4 - v5) / 2];
      if ( v3(*v7, *v5) )
      {
        v8 = *v7;
        *v7 = *v5;
        *v5 = v8;
      }
      if ( v3(*v4, *v7) )
      {
        v9 = *v4;
        *v4 = *v7;
        *v7 = v9;
      }
      if ( v3(*v7, *v5) )
      {
        v10 = *v7;
        *v7 = *v5;
        *v5 = v10;
      }
      v11 = lefta;
      v12 = *v7;
      v13 = v5;
      v19 = righta;
      v14 = righta;
      v22 = v13;
      if ( lefta <= righta )
      {
        do
        {
          if ( v3(*v13, v12) )
          {
            do
            {
              if ( v13 >= righta )
                break;
              v15 = v13[1];
              ++v13;
            }
            while ( v3(v15, v12) );
            v14 = v19;
            v22 = v13;
          }
          if ( v3(v12, *v14) )
          {
            do
            {
              if ( lefta >= v14 )
                break;
              v16 = *(v14 - 1);
              --v14;
            }
            while ( v3(v12, v16) );
            v13 = v22;
          }
          if ( v13 > v14 )
            break;
          v17 = *v14;
          v18 = *v13;
          --v14;
          *v13 = v17;
          ++v13;
          v14[1] = v18;
          v22 = v13;
          v19 = v14;
        }
        while ( v13 <= v14 );
        v11 = lefta;
      }
      if ( v11 < v14 )
        UFG::qQuickSortImpl<Render::Light *,bool (*)(Render::Light const *,Render::Light const *)>(v11, v14, v3);
      v4 = righta;
      if ( v13 >= righta )
        break;
      v5 = v13;
      lefta = v13;
      v6 = (unsigned __int64)(righta - v13) + 1;
      if ( v6 < 32 )
        goto LABEL_24;
    }
  }
}

// File Line: 219
// RVA: 0x1EBEB0
void __fastcall UFG::qQuickSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(UFG::PropertyLookup *array, int size, bool (__fastcall *predicate)(UFG::PropertyLookup *, UFG::PropertyLookup *))
{
  UFG::qQuickSortImpl<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
    array,
    &array[size - 1],
    predicate);
}

// File Line: 240
// RVA: 0x1ECB50
void __fastcall UFG::qSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(UFG::PropertyLookup *array, int size, bool (__fastcall *predicate)(UFG::PropertyLookup *, UFG::PropertyLookup *))
{
  UFG::qQuickSort<UFG::PropertyLookup,bool (*)(UFG::PropertyLookup const &,UFG::PropertyLookup const &)>(
    array,
    size,
    predicate);
}

