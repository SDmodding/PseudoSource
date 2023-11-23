// File Line: 21
// RVA: 0x1464E0
__int64 __fastcall UFG::ExternalSourceUtil::GetRandomVariation(
        unsigned int baseHash,
        unsigned int *final_hash,
        int lastVar)
{
  unsigned int v6; // eax
  int StreamFileSize; // eax
  int v9; // esi
  unsigned int v10; // eax
  UFG::WwiseFilePackageLowLevelIODeferred **p; // rbx
  unsigned int v12; // edi
  __int64 v13; // rax
  int v14; // ebx
  unsigned int i; // edi
  int v16[6]; // [rsp+20h] [rbp-48h] BYREF
  char v17; // [rsp+38h] [rbp-30h]
  int v18; // [rsp+3Ch] [rbp-2Ch]
  __int16 str; // [rsp+88h] [rbp+20h] BYREF

  str = 65;
  v6 = UFG::qWiseSymbolUIDFromString((const char *)&str, baseHash);
  StreamFileSize = UFG::WwiseInterface::GetStreamFileSize(v6);
  if ( StreamFileSize )
  {
    v9 = 0;
    if ( StreamFileSize > 0 )
    {
      do
      {
        LOBYTE(str) = str + 1;
        ++v9;
        v10 = UFG::qWiseSymbolUIDFromString((const char *)&str, baseHash);
        p = UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p;
        v18 = -1;
        v17 = 0;
        v12 = v10;
        v16[0] = 0;
        v16[1] = 4;
        if ( UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
          break;
        while ( 1 )
        {
          v13 = ((__int64 (__fastcall *)(UFG::WwiseFilePackageLowLevelIODeferred *, _QWORD, int *))(*p)->UFG::WwiseFilePackageLowLevelIO<UFG::WwiseDefaultIOHookDeferred>::UFG::WwiseDefaultIOHookDeferred::UFG::WwiseDefaultIOHookDeferredBase::AK::StreamMgr::IAkFileLocationResolver::vfptr[1].Open)(
                  *p,
                  v12,
                  v16);
          if ( v13 )
            break;
          if ( ++p == &UFG::WwiseInterface::sm_WwiseLowLevelIODevices.p[UFG::WwiseInterface::sm_WwiseLowLevelIODevices.size] )
            goto LABEL_9;
        }
      }
      while ( (int)v13 > 0 );
    }
LABEL_9:
    v14 = 6;
    for ( i = UFG::qRandom(v9, &UFG::qDefaultSeed); i == lastVar; i = UFG::qRandom(v9, &UFG::qDefaultSeed) )
    {
      if ( v14 < 0 )
        break;
      --v14;
    }
    LOBYTE(str) = i + 65;
    *final_hash = UFG::qWiseSymbolUIDFromString((const char *)&str, baseHash);
    return i;
  }
  else
  {
    *final_hash = 0;
    return 0xFFFFFFFFi64;
  }
}

// File Line: 66
// RVA: 0x13FE30
void __fastcall UFG::ArgumentSequencer::ArgumentSequencer(UFG::ArgumentSequencer *this)
{
  UFG::ArgumentSequencerBase::ArgumentSequencerBase(this);
  this->vfptr = (UFG::ArgumentSequencerBaseVtbl *)&UFG::ArgumentSequencer::`vftable;
}

// File Line: 83
// RVA: 0x14B960
char __fastcall UFG::ArgumentSequencer::SequenceArgs(UFG::ArgumentSequencer *this, UFG::DialogArgList *args)
{
  UFG::ArgumentSequencer *v3; // rbx
  unsigned int m_uDialogEventId; // edx
  UFG::qBaseTreeRB *v5; // rax
  int *p_mCount; // r13
  __int64 v7; // rbp
  __int64 v8; // r12
  unsigned int v9; // edx
  UFG::qBaseTreeRB *v10; // rax
  int *v11; // r14
  unsigned int m_nArgs; // esi
  __int64 v13; // rbx
  unsigned int *v14; // rdi
  UFG::qBaseTreeRB *v15; // rax
  int v17[22]; // [rsp+30h] [rbp-58h] BYREF
  unsigned int v19; // [rsp+98h] [rbp+10h]

  v3 = this;
  m_uDialogEventId = args->m_uDialogEventId;
  if ( m_uDialogEventId )
  {
    v5 = UFG::qBaseTreeRB::Get(&this->m_events.mTree, m_uDialogEventId);
    if ( v5 )
    {
      p_mCount = &v5[-1].mCount;
      if ( v5 != (UFG::qBaseTreeRB *)8 )
      {
        v17[0] = args->m_args[0];
        v17[1] = args->m_args[1];
        v17[2] = args->m_args[2];
        v17[3] = args->m_args[3];
        v17[4] = args->m_args[4];
        v17[5] = args->m_args[5];
        v17[6] = args->m_nArgs;
        v17[7] = args->m_uDialogEventId;
        v7 = 0i64;
        v19 = p_mCount[10];
        if ( v19 )
        {
          v8 = 0i64;
          do
          {
            v9 = *(_DWORD *)(v8 + *((_QWORD *)p_mCount + 6));
            if ( v9
              && (v10 = UFG::qBaseTreeRB::Get(&v3->m_argumentGroup.mTree, v9)) != 0i64
              && (v11 = &v10[-1].mCount, v10 != (UFG::qBaseTreeRB *)8)
              && (m_nArgs = args->m_nArgs, v13 = 0i64, m_nArgs) )
            {
              v14 = (unsigned int *)v17;
              while ( 1 )
              {
                if ( *v14 )
                {
                  v15 = UFG::qBaseTreeRB::Get((UFG::qBaseTreeRB *)(v11 + 10), *v14);
                  if ( v15 )
                    break;
                }
                v13 = (unsigned int)(v13 + 1);
                ++v14;
                if ( (unsigned int)v13 >= m_nArgs )
                  goto LABEL_16;
              }
              args->m_args[v7] = v15->mRoot.mUID;
              v17[v13] = 0;
            }
            else
            {
LABEL_16:
              args->m_args[v7] = 0;
            }
            v7 = (unsigned int)(v7 + 1);
            v8 += 4i64;
            v3 = this;
          }
          while ( (unsigned int)v7 < v19 );
        }
        args->m_nArgs = v7;
      }
    }
  }
  return 1;
}

