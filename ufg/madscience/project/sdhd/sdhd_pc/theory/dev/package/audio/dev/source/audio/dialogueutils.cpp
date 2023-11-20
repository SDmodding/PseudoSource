// File Line: 21
// RVA: 0x1464E0
signed __int64 __fastcall UFG::ExternalSourceUtil::GetRandomVariation(unsigned int baseHash, unsigned int *final_hash, int lastVar)
{
  unsigned int *v3; // r12
  unsigned int v4; // er15
  int v5; // er14
  unsigned int v6; // eax
  int v7; // eax
  signed __int64 result; // rax
  int v9; // esi
  unsigned int v10; // eax
  UFG::WwiseFilePackageLowLevelIODeferred **v11; // rbx
  unsigned int v12; // edi
  __int64 v13; // rax
  signed int v14; // ebx
  unsigned int i; // edi
  int v16; // [rsp+20h] [rbp-48h]
  int v17; // [rsp+24h] [rbp-44h]
  char v18; // [rsp+38h] [rbp-30h]
  int v19; // [rsp+3Ch] [rbp-2Ch]
  __int16 str; // [rsp+88h] [rbp+20h]

  v3 = final_hash;
  v4 = baseHash;
  v5 = lastVar;
  str = 65;
  v6 = UFG::qWiseSymbolUIDFromString((const char *)&str, baseHash);
  v7 = UFG::WwiseInterface::GetStreamFileSize(v6);
  if ( v7 )
  {
    v9 = 0;
    if ( v7 > 0 )
    {
      do
      {
        LOBYTE(str) = str + 1;
        ++v9;
        v10 = UFG::qWiseSymbolUIDFromString((const char *)&str, v4);
        v11 = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        v19 = -1;
        v18 = 0;
        v12 = v10;
        v16 = 0;
        v17 = 4;
        if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
          break;
        while ( 1 )
        {
          v13 = ((__int64 (__fastcall *)(UFG::WwiseFilePackageLowLevelIODeferred *, _QWORD, int *))(*v11)->vfptr[1].Open)(
                  *v11,
                  v12,
                  &v16);
          if ( v13 )
            break;
          ++v11;
          if ( v11 == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
            goto LABEL_9;
        }
      }
      while ( (signed int)v13 > 0 );
    }
LABEL_9:
    v14 = 6;
    for ( i = UFG::qRandom(v9, &UFG::qDefaultSeed); i == v5; i = UFG::qRandom(v9, &UFG::qDefaultSeed) )
    {
      if ( v14 < 0 )
        break;
      --v14;
    }
    LOBYTE(str) = i + 65;
    *v3 = UFG::qWiseSymbolUIDFromString((const char *)&str, v4);
    result = i;
  }
  else
  {
    *v3 = 0;
    result = 0xFFFFFFFFi64;
  }
  return result;
}

// File Line: 66
// RVA: 0x13FE30
void __fastcall UFG::ArgumentSequencer::ArgumentSequencer(UFG::ArgumentSequencer *this)
{
  UFG::ArgumentSequencer *v1; // rbx

  v1 = this;
  UFG::ArgumentSequencerBase::ArgumentSequencerBase((UFG::ArgumentSequencerBase *)&this->vfptr);
  v1->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencer::`vftable;
}

// File Line: 83
// RVA: 0x14B960
char __fastcall UFG::ArgumentSequencer::SequenceArgs(UFG::ArgumentSequencer *this, UFG::DialogArgList *args)
{
  UFG::DialogArgList *v2; // r15
  UFG::ArgumentSequencer *v3; // rbx
  unsigned int v4; // edx
  UFG::qBaseTreeRB *v5; // rax
  signed __int64 v6; // r13
  __int64 v7; // rbp
  __int64 v8; // r12
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  signed __int64 v11; // r14
  unsigned int v12; // esi
  __int64 v13; // rbx
  unsigned int *v14; // rdi
  UFG::qBaseTreeRB *v15; // rax
  unsigned int v17; // [rsp+30h] [rbp-58h]
  unsigned int v18; // [rsp+34h] [rbp-54h]
  unsigned int v19; // [rsp+38h] [rbp-50h]
  unsigned int v20; // [rsp+3Ch] [rbp-4Ch]
  unsigned int v21; // [rsp+40h] [rbp-48h]
  unsigned int v22; // [rsp+44h] [rbp-44h]
  unsigned int v23; // [rsp+48h] [rbp-40h]
  unsigned int v24; // [rsp+4Ch] [rbp-3Ch]
  UFG::ArgumentSequencer *v25; // [rsp+90h] [rbp+8h]
  unsigned int v26; // [rsp+98h] [rbp+10h]

  v25 = this;
  v2 = args;
  v3 = this;
  v4 = args->m_uDialogEventId;
  if ( v4 )
  {
    v5 = UFG::qBaseTreeRB::Get(&this->m_events.mTree, v4);
    if ( v5 )
    {
      v6 = (signed __int64)&v5[-1].mCount;
      if ( v5 != (UFG::qBaseTreeRB *)8 )
      {
        v17 = v2->m_args[0];
        v18 = v2->m_args[1];
        v19 = v2->m_args[2];
        v20 = v2->m_args[3];
        v21 = v2->m_args[4];
        v22 = v2->m_args[5];
        v23 = v2->m_nArgs;
        v24 = v2->m_uDialogEventId;
        v7 = 0i64;
        v26 = *(_DWORD *)(v6 + 40);
        if ( v26 )
        {
          v8 = 0i64;
          do
          {
            v9 = *(_DWORD *)(v8 + *(_QWORD *)(v6 + 48));
            if ( v9
              && (v10 = UFG::qBaseTreeRB::Get(&v3->m_argumentGroup.mTree, v9)) != 0i64
              && (v11 = (signed __int64)&v10[-1].mCount, v10 != (UFG::qBaseTreeRB *)8)
              && (v12 = v2->m_nArgs, v13 = 0i64, v12) )
            {
              v14 = &v17;
              while ( 1 )
              {
                if ( *v14 )
                {
                  v15 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(v11 + 40), *v14);
                  if ( v15 )
                    break;
                }
                v13 = (unsigned int)(v13 + 1);
                ++v14;
                if ( (unsigned int)v13 >= v12 )
                  goto LABEL_16;
              }
              v2->m_args[v7] = v15->mRoot.mUID;
              *(&v17 + v13) = 0;
            }
            else
            {
LABEL_16:
              v2->m_args[v7] = 0;
            }
            v7 = (unsigned int)(v7 + 1);
            v8 += 4i64;
            v3 = v25;
          }
          while ( (unsigned int)v7 < v26 );
        }
        v2->m_nArgs = v7;
      }
    }
  }
  return 1;
}

