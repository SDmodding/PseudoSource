// File Line: 23
// RVA: 0x80D090
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::File *obj)
{
  Scaleform::GFx::AS3::Abc::Reader *v2; // rdi
  Scaleform::GFx::AS3::Abc::File *v3; // rbx
  const char *v4; // rax
  __int16 v5; // r9
  __int16 v6; // r8
  const char *v7; // rax
  __int16 v8; // dx
  __int16 v9; // cx
  unsigned __int16 v10; // dx

  v2 = this;
  v3 = obj;
  Scaleform::GFx::AS3::Abc::File::Clear(obj);
  v4 = v2->CP;
  v5 = *((unsigned __int8 *)v4 + 1);
  v6 = *(unsigned __int8 *)v4;
  v2->CP = v4 + 2;
  v3->MinorVersion = v6 | (v5 << 8);
  v7 = v2->CP;
  v8 = *((unsigned __int8 *)v7 + 1);
  v9 = *(unsigned __int8 *)v7;
  v2->CP = v7 + 2;
  v10 = v9 | (v8 << 8);
  v3->MajorVersion = v10;
  return v10 == 46
      && v3->MinorVersion == 16
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Const_Pool)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Methods)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Const_Pool, &v3->Metadata)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Traits, &v3->AS3_Classes)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Traits, &v3->Scripts)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v2, &v3->Traits, &v3->Methods, &v3->MethodBodies);
}

// File Line: 48
// RVA: 0x80E850
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *cp, Scaleform::StringDataPtr *obj, Scaleform::StringDataPtr *zero_val)
{
  const char *v4; // rax
  unsigned int v5; // er11
  Scaleform::StringDataPtr *v6; // rsi
  char v7; // r10
  Scaleform::GFx::AS3::Abc::Reader *v8; // rdi
  Scaleform::GFx::AS3::Abc::ConstPool *v9; // r8
  __int64 v10; // rbx
  unsigned int v11; // ecx
  char v12; // dl
  int v13; // eax
  unsigned __int64 v14; // rax
  const char *v15; // r8
  char *v16; // r8
  char v17; // al
  int v18; // er9
  char v19; // dl
  char v20; // cl

  v4 = this->CP;
  v5 = 7;
  v6 = obj;
  v7 = *v4;
  v8 = this;
  this->CP = v4 + 1;
  v9 = cp;
  v10 = v7 & 0x7F;
  v11 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v11 >= 0x20 )
        break;
      v12 = *v8->CP++;
      v13 = (v12 & 0x7F) << v11;
      v11 += 7;
      v10 = v13 | (unsigned int)v10;
    }
    while ( v12 < 0 );
  }
  if ( (_DWORD)v10 )
  {
    v15 = v9->ConstStr.Data.Data[v10].Data;
    if ( v15 )
    {
      v17 = *v15;
      v16 = (char *)(v15 + 1);
      v18 = v17 & 0x7F;
      if ( v17 < 0 )
      {
        do
        {
          if ( v5 >= 0x20 )
            break;
          v19 = *v16;
          v20 = v5;
          ++v16;
          v5 += 7;
          v18 |= (v19 & 0x7F) << v20;
        }
        while ( v19 < 0 );
      }
      v14 = v18;
    }
    else
    {
      v16 = &customWorldMapCaption;
      v14 = 0i64;
    }
    v6->pStr = v16;
  }
  else
  {
    v6->pStr = zero_val->pStr;
    v14 = zero_val->Size;
  }
  v6->Size = v14;
  return 1;
}

// File Line: 64
// RVA: 0x80E730
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *cp, Scaleform::GFx::AS3::Abc::NamespaceInfo *obj)
{
  const char *v3; // rax
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v4; // rdi
  int v5; // ebx
  bool result; // al
  Scaleform::StringDataPtr zero_val; // [rsp+20h] [rbp-18h]

  v3 = this->CP;
  v4 = obj;
  v5 = *(unsigned __int8 *)v3;
  this->CP = v3 + 1;
  zero_val.Size = 0i64;
  zero_val.pStr = &customWorldMapCaption;
  result = Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->NameURI, &zero_val) != 0;
  switch ( v5 )
  {
    case 5:
      v4->Kind = 3;
      break;
    case 8:
    case 22:
      v4->Kind = 0;
      break;
    case 23:
      v4->Kind = 5;
      break;
    case 24:
      v4->Kind = 1;
      break;
    case 25:
      v4->Kind = 4;
      break;
    case 26:
      v4->Kind = 2;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 130
// RVA: 0x80E490
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *cp, Scaleform::GFx::AS3::Abc::Multiname *obj)
{
  const char *v3; // rax
  Scaleform::GFx::AS3::Abc::ConstPool *v4; // r11
  Scaleform::GFx::AS3::Abc::Multiname *v5; // rdi
  int v6; // er9
  Scaleform::GFx::AS3::Abc::Reader *v7; // rbx
  char v8; // r10
  Scaleform::GFx::AS3::Abc::MultinameKind v9; // eax
  Scaleform::GFx::AS3::Abc::Multiname *v10; // rdx
  const char *v12; // rax
  unsigned int v13; // er8
  char v14; // cl
  unsigned int v15; // er9
  int v16; // er10
  const char *v17; // rax
  char v18; // cl
  char v19; // dl
  Scaleform::GFx::AS3::Abc::Multiname *v20; // rdx
  const char *v21; // rax
  char v22; // cl
  int v23; // er9
  const char *v24; // rax
  char v25; // cl
  char v26; // dl

  v3 = this->CP;
  v4 = cp;
  v5 = obj;
  v6 = *(unsigned __int8 *)v3;
  v7 = this;
  this->CP = v3 + 1;
  v8 = 1;
  switch ( v6 )
  {
    case 7:
      v9 = 0;
      break;
    case 9:
      v9 = 2;
      break;
    case 13:
      v9 = 8;
      break;
    case 14:
      v9 = 10;
      break;
    case 15:
      v9 = 1;
      break;
    case 16:
      v9 = 9;
      break;
    case 17:
      v9 = 5;
      break;
    case 18:
      v9 = 13;
      break;
    case 27:
      v9 = 6;
      break;
    case 28:
      v9 = 14;
      break;
    case 29:
      v9 = 16;
      break;
    default:
      v9 = 32;
      v8 = 0;
      break;
  }
  obj->Kind = v9;
  switch ( v9 )
  {
    case 0:
    case 8:
      if ( !v8 || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)obj) )
        goto LABEL_20;
      v10 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)v5 + 8);
      goto LABEL_18;
    case 1:
    case 9:
      if ( !v8 )
        goto LABEL_20;
      v10 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)obj + 8);
      goto LABEL_18;
    case 2:
    case 10:
      if ( !v8 || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->NameIndex) )
        goto LABEL_20;
      v10 = v5;
      goto LABEL_18;
    case 6:
    case 14:
      if ( !v8 )
        goto LABEL_20;
      v10 = obj;
      goto LABEL_18;
    case 16:
      if ( v8 )
      {
        v12 = this->CP;
        v13 = 7;
        v14 = *v12;
        v15 = 7;
        v7->CP = v12 + 1;
        v16 = v14 & 0x7F;
        if ( v14 < 0 )
        {
          do
          {
            if ( v15 >= 0x20 )
              break;
            v17 = v7->CP;
            v18 = v15;
            v15 += 7;
            v19 = *v17;
            v7->CP = v17 + 1;
            v16 |= (v19 & 0x7F) << v18;
          }
          while ( v19 < 0 );
        }
        v20 = &v4->const_multiname.Data.Data[v16];
        v5->Ind = v20->Ind;
        v5->NextIndex = v20->NextIndex;
        v5->NameIndex = v20->NameIndex;
        v5->Kind = v20->Kind;
        v21 = v7->CP;
        v22 = *v21;
        v7->CP = v21 + 1;
        v23 = v22 & 0x7F;
        if ( v22 < 0 )
        {
          do
          {
            if ( v13 >= 0x20 )
              break;
            v24 = v7->CP;
            v25 = v13;
            v13 += 7;
            v26 = *v24;
            v7->CP = v24 + 1;
            v23 |= (v26 & 0x7F) << v25;
          }
          while ( v26 < 0 );
        }
        if ( v23 == 1 )
        {
          v10 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)v5 + 4);
LABEL_18:
          if ( Scaleform::GFx::AS3::Abc::Reader::Read(v7, (unsigned int *)v10) )
            return 1;
        }
      }
LABEL_20:
      v8 = 0;
LABEL_38:
      v5->Kind = 32;
      return v8;
    default:
      if ( !v8 )
        goto LABEL_38;
      return v8;
  }
}

// File Line: 227
// RVA: 0x80C230
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *obj)
{
  Scaleform::GFx::AS3::Abc::ConstPool *v2; // r12
  Scaleform::GFx::AS3::Abc::Reader *v3; // rdi
  const char *v4; // rax
  char v5; // r8
  unsigned int v6; // esi
  unsigned int v7; // ecx
  const char *v8; // rax
  char v9; // dl
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // r8
  const char *v13; // r15
  const char *v14; // rax
  char v15; // cl
  int v16; // er14
  unsigned int v17; // er8
  const char *v18; // rax
  char v19; // dl
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  const char *v23; // rax
  char v24; // cl
  unsigned int v25; // esi
  unsigned int v26; // er8
  const char *v27; // rax
  char v28; // dl
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // r14
  unsigned __int64 v31; // r8
  const char *v32; // rax
  char v33; // cl
  int v34; // er14
  unsigned int v35; // er8
  const char *v36; // rax
  char v37; // dl
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // rsi
  unsigned __int64 v40; // r8
  const char *v41; // rax
  char v42; // cl
  int v43; // er9
  unsigned int v44; // er8
  const char *v45; // rax
  char v46; // dl
  const char *v47; // rax
  char v48; // cl
  unsigned int v49; // ebx
  unsigned int v50; // er8
  const char *v51; // rax
  char v52; // dl
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *v53; // rsi
  unsigned __int64 v54; // rax
  unsigned __int64 v55; // r14
  unsigned __int64 v56; // r8
  Scaleform::GFx::AS3::Abc::StringView *v57; // rcx
  unsigned int v58; // er12
  const char *v59; // rbx
  unsigned __int64 v60; // rax
  unsigned __int64 v61; // r14
  unsigned __int64 v62; // r8
  Scaleform::GFx::AS3::Abc::StringView *v63; // rcx
  const char *v64; // rax
  char v65; // cl
  int v66; // er9
  unsigned int v67; // er8
  const char *v68; // rax
  char v69; // dl
  const char *v70; // rax
  char v71; // cl
  unsigned int v72; // esi
  unsigned int v73; // er8
  const char *v74; // rax
  char v75; // dl
  bool v76; // r15
  Scaleform::GFx::AS3::Abc::ConstPool *v77; // r13
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // r14
  unsigned __int64 v80; // r8
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v81; // rax
  signed __int64 v82; // rdx
  signed __int64 v83; // r14
  __int64 v84; // r12
  unsigned __int64 v85; // rax
  unsigned __int64 v86; // rsi
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v87; // rdx
  unsigned __int64 v88; // rax
  unsigned __int64 v89; // rax
  signed __int64 v90; // r14
  unsigned __int64 v91; // r8
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v92; // rax
  unsigned __int64 v93; // rax
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v94; // rax
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v95; // rdx
  const char *v96; // rax
  char v97; // cl
  unsigned int v98; // ebx
  unsigned int v99; // er15
  signed __int64 v100; // r8
  const char *v101; // rax
  char v102; // dl
  char v103; // r12
  signed __int64 v104; // rsi
  void *v105; // rdx
  unsigned __int64 v106; // rax
  unsigned __int64 v107; // r8
  void *v108; // rax
  unsigned __int64 v109; // rax
  unsigned __int64 v110; // r14
  unsigned __int64 v111; // r8
  __int64 v112; // r13
  Scaleform::GFx::AS3::Abc::ConstPool *v113; // rbx
  char v114; // cl
  unsigned int v115; // er11
  const char *v116; // rax
  char v117; // dl
  unsigned int i; // er10
  const char *v119; // rax
  char v120; // cl
  int v121; // er9
  const char *v122; // rax
  char v123; // dl
  unsigned __int64 v124; // rax
  unsigned __int64 v125; // r14
  void *v126; // rdx
  unsigned __int64 v127; // rax
  unsigned __int64 v128; // rax
  signed __int64 v129; // r15
  unsigned __int64 v130; // r8
  void *v131; // rax
  unsigned __int64 v132; // rax
  const char *v134; // rax
  char v135; // cl
  unsigned int v136; // er14
  const char *v137; // rax
  char v138; // dl
  bool v139; // r15
  unsigned __int64 v140; // rsi
  void **v141; // rbx
  void *v142; // rdx
  unsigned __int64 v143; // rsi
  unsigned __int64 v144; // r8
  void *v145; // rax
  unsigned __int64 v146; // rax
  unsigned __int64 v147; // rsi
  void *v148; // rdx
  signed __int64 v149; // r12
  unsigned __int64 v150; // r12
  unsigned __int64 v151; // r8
  void *v152; // rax
  unsigned __int64 v153; // r12
  int *v154; // rcx
  __int64 v155; // r12
  unsigned __int64 v156; // rax
  unsigned __int64 v157; // rsi
  void *v158; // rdx
  unsigned __int64 v159; // r8
  void *v160; // rax
  signed __int64 v161; // rdx
  signed __int64 v162; // [rsp+20h] [rbp-20h]
  Scaleform::GFx::AS3::Abc::NamespaceInfo obja; // [rsp+28h] [rbp-18h]
  Scaleform::GFx::AS3::Abc::ConstPool *cp; // [rsp+88h] [rbp+48h]
  unsigned __int64 v165; // [rsp+90h] [rbp+50h]
  unsigned __int64 v166; // [rsp+98h] [rbp+58h]

  cp = obj;
  v162 = -2i64;
  v2 = obj;
  v3 = this;
  v4 = this->CP;
  v5 = *v4;
  this->CP = v4 + 1;
  v6 = v5 & 0x7F;
  v7 = 7;
  if ( v5 < 0 )
  {
    do
    {
      if ( v7 >= 0x20 )
        break;
      v8 = v3->CP;
      v9 = *v8;
      v3->CP = v8 + 1;
      v6 |= (v9 & 0x7F) << v7;
      v7 += 7;
    }
    while ( v9 < 0 );
  }
  if ( v6 > v2->ConstInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstInt,
      &v2->ConstInt,
      v6);
  v10 = v2->ConstInt.Data.Size;
  v11 = v10 + 1;
  if ( v10 + 1 >= v10 )
  {
    if ( v11 <= v2->ConstInt.Data.Policy.Capacity )
      goto LABEL_12;
    v12 = v11 + (v11 >> 2);
  }
  else
  {
    if ( v11 >= v2->ConstInt.Data.Policy.Capacity >> 1 )
      goto LABEL_12;
    v12 = v10 + 1;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstInt,
    &v2->ConstInt,
    v12);
LABEL_12:
  v2->ConstInt.Data.Size = v11;
  v13 = 0i64;
  v2->ConstInt.Data.Data[v11 - 1] = 0;
  if ( v6 > 1 )
  {
    v13 = (const char *)(v6 - 1);
    do
    {
      v14 = v3->CP;
      v15 = *v14;
      v3->CP = v14 + 1;
      v16 = v15 & 0x7F;
      v17 = 7;
      if ( v15 < 0 )
      {
        do
        {
          if ( v17 >= 0x20 )
            break;
          v18 = v3->CP;
          v19 = *v18;
          v3->CP = v18 + 1;
          v16 |= (v19 & 0x7F) << v17;
          v17 += 7;
        }
        while ( v19 < 0 );
      }
      v20 = v2->ConstInt.Data.Size;
      v21 = v20 + 1;
      if ( v20 + 1 >= v20 )
      {
        if ( v21 > v2->ConstInt.Data.Policy.Capacity )
        {
          v22 = v21 + (v21 >> 2);
          goto LABEL_22;
        }
      }
      else if ( v21 < v2->ConstInt.Data.Policy.Capacity >> 1 )
      {
        v22 = v20 + 1;
LABEL_22:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstInt,
          &v2->ConstInt,
          v22);
        goto LABEL_23;
      }
LABEL_23:
      v2->ConstInt.Data.Size = v21;
      v2->ConstInt.Data.Data[v21 - 1] = v16;
      --v13;
    }
    while ( v13 );
  }
  v23 = v3->CP;
  v24 = *v23;
  v3->CP = v23 + 1;
  v25 = v24 & 0x7F;
  v26 = 7;
  if ( v24 < 0 )
  {
    do
    {
      if ( v26 >= 0x20 )
        break;
      v27 = v3->CP;
      v28 = *v27;
      v3->CP = v27 + 1;
      v25 |= (v28 & 0x7F) << v26;
      v26 += 7;
    }
    while ( v28 < 0 );
  }
  if ( v25 > v2->ConstUInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstUInt.Data.Data,
      &v2->ConstUInt,
      v25);
  v29 = v2->ConstUInt.Data.Size;
  v30 = v29 + 1;
  if ( v29 + 1 >= v29 )
  {
    if ( v30 <= v2->ConstUInt.Data.Policy.Capacity )
      goto LABEL_35;
    v31 = v30 + (v30 >> 2);
  }
  else
  {
    if ( v30 >= v2->ConstUInt.Data.Policy.Capacity >> 1 )
      goto LABEL_35;
    v31 = v29 + 1;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstUInt.Data.Data,
    &v2->ConstUInt,
    v31);
LABEL_35:
  v2->ConstUInt.Data.Size = v30;
  v2->ConstUInt.Data.Data[v30 - 1] = (unsigned int)v13;
  if ( v25 > 1 )
  {
    v13 = (const char *)(v25 - 1);
    do
    {
      v32 = v3->CP;
      v33 = *v32;
      v3->CP = v32 + 1;
      v34 = v33 & 0x7F;
      v35 = 7;
      if ( v33 < 0 )
      {
        do
        {
          if ( v35 >= 0x20 )
            break;
          v36 = v3->CP;
          v37 = *v36;
          v3->CP = v36 + 1;
          v34 |= (v37 & 0x7F) << v35;
          v35 += 7;
        }
        while ( v37 < 0 );
      }
      v38 = v2->ConstUInt.Data.Size;
      v39 = v38 + 1;
      if ( v38 + 1 >= v38 )
      {
        if ( v39 > v2->ConstUInt.Data.Policy.Capacity )
        {
          v40 = v39 + (v39 >> 2);
          goto LABEL_45;
        }
      }
      else if ( v39 < v2->ConstUInt.Data.Policy.Capacity >> 1 )
      {
        v40 = v38 + 1;
LABEL_45:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstUInt.Data.Data,
          &v2->ConstUInt,
          v40);
        goto LABEL_46;
      }
LABEL_46:
      v2->ConstUInt.Data.Size = v39;
      v2->ConstUInt.Data.Data[v39 - 1] = v34;
      --v13;
    }
    while ( v13 );
  }
  v2->DoubleCount = (unsigned int)v13;
  v2->Doubles = v13;
  v41 = v3->CP;
  v42 = *v41;
  v3->CP = v41 + 1;
  v43 = v42 & 0x7F;
  v44 = 7;
  if ( v42 < 0 )
  {
    do
    {
      if ( v44 >= 0x20 )
        break;
      v45 = v3->CP;
      v46 = *v45;
      v3->CP = v45 + 1;
      v43 |= (v46 & 0x7F) << v44;
      v44 += 7;
    }
    while ( v46 < 0 );
  }
  v2->DoubleCount = v43;
  v2->Doubles = v3->CP;
  if ( v43 )
    v3->CP += (unsigned int)(8 * v43 - 8);
  v47 = v3->CP;
  v48 = *v47;
  v3->CP = v47 + 1;
  v49 = v48 & 0x7F;
  v50 = 7;
  if ( v48 < 0 )
  {
    do
    {
      if ( v50 >= 0x20 )
        break;
      v51 = v3->CP;
      v52 = *v51;
      v3->CP = v51 + 1;
      v49 |= (v52 & 0x7F) << v50;
      v50 += 7;
    }
    while ( v52 < 0 );
  }
  v53 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstStr.Data.Data;
  if ( v49 > v2->ConstStr.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstStr.Data.Data,
      &v2->ConstStr,
      v49);
  v54 = v2->ConstStr.Data.Size;
  v55 = v54 + 1;
  if ( v54 + 1 >= v54 )
  {
    if ( v55 <= v2->ConstStr.Data.Policy.Capacity )
      goto LABEL_63;
    v56 = v55 + (v55 >> 2);
  }
  else
  {
    if ( v55 >= v2->ConstStr.Data.Policy.Capacity >> 1 )
      goto LABEL_63;
    v56 = v54 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *)&v2->ConstStr.Data.Data,
    &v2->ConstStr,
    v56);
LABEL_63:
  v2->ConstStr.Data.Size = v55;
  v57 = &v53->Data[v55 - 1];
  if ( v57 )
    v57->Data = Scaleform::GFx::AS3::Abc::StringView::Empty;
  if ( v49 )
  {
    v58 = v49 - 1;
    while ( 1 )
    {
      if ( (unsigned int)v13 >= v58 )
        break;
      v59 = v3->CP;
      v60 = v53->Size;
      v61 = v60 + 1;
      if ( v60 + 1 >= v60 )
      {
        if ( v61 <= v53->Policy.Capacity )
          goto LABEL_74;
        v62 = v61 + (v61 >> 2);
      }
      else
      {
        if ( v61 >= v53->Policy.Capacity >> 1 )
          goto LABEL_74;
        v62 = v60 + 1;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v53,
        v53,
        v62);
LABEL_74:
      v53->Size = v61;
      v63 = &v53->Data[v61 - 1];
      if ( v63 )
        v63->Data = v59;
      v64 = v3->CP;
      v65 = *v64;
      v3->CP = v64 + 1;
      v66 = v65 & 0x7F;
      v67 = 7;
      if ( v65 < 0 )
      {
        do
        {
          if ( v67 >= 0x20 )
            break;
          v68 = v3->CP;
          v69 = *v68;
          v3->CP = v68 + 1;
          v66 |= (v69 & 0x7F) << v67;
          v67 += 7;
        }
        while ( v69 < 0 );
      }
      v3->CP += v66;
      LODWORD(v13) = (_DWORD)v13 + 1;
    }
  }
  v70 = v3->CP;
  v71 = *v70;
  v3->CP = v70 + 1;
  v72 = v71 & 0x7F;
  v73 = 7;
  if ( v71 < 0 )
  {
    do
    {
      if ( v73 >= 0x20 )
        break;
      v74 = v3->CP;
      v75 = *v74;
      v3->CP = v74 + 1;
      v72 |= (v75 & 0x7F) << v73;
      v73 += 7;
    }
    while ( v75 < 0 );
  }
  v76 = 1;
  v77 = cp;
  if ( v72 > cp->ConstNamespace.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy> *)&cp->ConstNamespace.Data.Data,
      &cp->ConstNamespace,
      v72);
  v78 = v77->ConstNamespace.Data.Size;
  v79 = v78 + 1;
  if ( v78 + 1 >= v78 )
  {
    if ( v79 > v77->ConstNamespace.Data.Policy.Capacity )
    {
      v80 = v79 + (v79 >> 2);
      goto LABEL_90;
    }
  }
  else if ( v79 < v77->ConstNamespace.Data.Policy.Capacity >> 1 )
  {
    v80 = v78 + 1;
LABEL_90:
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy> *)&v77->ConstNamespace.Data.Data,
      &v77->ConstNamespace,
      v80);
    goto LABEL_91;
  }
LABEL_91:
  v77->ConstNamespace.Data.Size = v79;
  v81 = v77->ConstNamespace.Data.Data;
  v82 = (signed __int64)&v81[v79 - 1];
  v165 = (unsigned __int64)&v81[v79 - 1];
  v166 = (unsigned __int64)&v81[v79 - 1];
  v83 = 0i64;
  if ( v82 )
  {
    *(_DWORD *)v82 = 0;
    *(_QWORD *)(v82 + 8) = &customWorldMapCaption;
    *(_QWORD *)(v82 + 16) = 0i64;
  }
  if ( v72 <= 1 )
    goto LABEL_117;
  v84 = v72 - 1;
  do
  {
    obja.Kind = 0;
    obja.NameURI.pStr = &customWorldMapCaption;
    obja.NameURI.Size = 0i64;
    v76 = v76 && Scaleform::GFx::AS3::Abc::Reader::Read(v3, v77, &obja);
    v85 = v77->ConstNamespace.Data.Size;
    v86 = v85 + 1;
    if ( v85 + 1 >= v85 )
    {
      if ( v86 <= v77->ConstNamespace.Data.Policy.Capacity )
        goto LABEL_113;
      v87 = v77->ConstNamespace.Data.Data;
      v93 = v86 + (v86 >> 2);
      if ( v93 )
      {
        v88 = v93 + 3;
        goto LABEL_103;
      }
    }
    else
    {
      if ( v86 >= v77->ConstNamespace.Data.Policy.Capacity >> 1 )
        goto LABEL_113;
      v87 = v77->ConstNamespace.Data.Data;
      if ( v85 != -1i64 )
      {
        v88 = v85 + 4;
LABEL_103:
        v89 = v88 >> 2;
        v90 = 4 * v89;
        v91 = 96 * v89;
        if ( v87 )
        {
          v92 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             v87,
                                                             v91);
        }
        else
        {
          LODWORD(v165) = 339;
          v92 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, unsigned __int64 *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             &v77->ConstNamespace,
                                                             v91,
                                                             &v165,
                                                             v162);
        }
        v77->ConstNamespace.Data.Data = v92;
        v77->ConstNamespace.Data.Policy.Capacity = v90;
        v83 = 0i64;
        goto LABEL_113;
      }
    }
    if ( v87 )
    {
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v77->ConstNamespace.Data.Data = 0i64;
    }
    v77->ConstNamespace.Data.Policy.Capacity = 0i64;
LABEL_113:
    v77->ConstNamespace.Data.Size = v86;
    v94 = v77->ConstNamespace.Data.Data;
    v95 = &v94[v86 - 1];
    v165 = (unsigned __int64)&v94[v86 - 1];
    v166 = (unsigned __int64)&v94[v86 - 1];
    if ( v95 )
      *v95 = obja;
    --v84;
  }
  while ( v84 );
  if ( !v76 )
    return 0;
LABEL_117:
  v96 = v3->CP;
  v97 = *v96;
  v3->CP = v96 + 1;
  v98 = v97 & 0x7F;
  v99 = 7;
  v100 = 7i64;
  if ( v97 < 0 )
  {
    do
    {
      if ( (unsigned int)v100 >= 0x20 )
        break;
      v101 = v3->CP;
      v102 = *v101;
      v3->CP = v101 + 1;
      v98 |= (v102 & 0x7F) << v100;
      v100 = (unsigned int)(v100 + 7);
    }
    while ( v102 < 0 );
  }
  v103 = 1;
  v104 = (signed __int64)&v77->const_ns_set;
  if ( v98 > v77->const_ns_set.Data.Policy.Capacity )
  {
    v105 = *(void **)v104;
    if ( v98 )
    {
      v106 = ((unsigned __int64)v98 + 3) >> 2;
      v83 = 4 * v106;
      v107 = 32 * v106;
      if ( v105 )
      {
        v108 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v105, v107);
      }
      else
      {
        LODWORD(v165) = 339;
        v108 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, unsigned __int64 *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                         Scaleform::Memory::pGlobalHeap,
                         &v77->const_ns_set,
                         v107,
                         &v165,
                         v162);
      }
      *(_QWORD *)v104 = v108;
    }
    else if ( v105 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v105,
        v100);
      *(_QWORD *)v104 = 0i64;
    }
    v77->const_ns_set.Data.Policy.Capacity = v83;
  }
  v109 = v77->const_ns_set.Data.Size;
  v110 = v109 + 1;
  if ( v109 + 1 >= v109 )
  {
    if ( v110 > v77->const_ns_set.Data.Policy.Capacity )
    {
      v111 = v110 + (v110 >> 2);
LABEL_134:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *)&v77->const_ns_set,
        &v77->const_ns_set,
        v111);
    }
  }
  else if ( v110 < v77->const_ns_set.Data.Policy.Capacity >> 1 )
  {
    v111 = v109 + 1;
    goto LABEL_134;
  }
  v77->const_ns_set.Data.Size = v110;
  *(_QWORD *)(*(_QWORD *)v104 + 8 * v110 - 8) = cp;
  *(_QWORD *)(*(_QWORD *)v104 + 8 * v77->const_ns_set.Data.Size - 8) = 0i64;
  if ( v98 <= 1 )
    goto LABEL_168;
  v112 = v98 - 1;
  v113 = cp;
  while ( 2 )
  {
    if ( v103 )
    {
      v113 = (Scaleform::GFx::AS3::Abc::ConstPool *)v3->CP;
      v114 = v113->DoubleCount;
      v3->CP = (char *)&v113->DoubleCount + 1;
      v115 = v114 & 0x7F;
      v100 = 7i64;
      if ( v114 < 0 )
      {
        do
        {
          if ( (unsigned int)v100 >= 0x20 )
            break;
          v116 = v3->CP;
          v117 = *v116;
          v3->CP = v116 + 1;
          v115 |= (v117 & 0x7F) << v100;
          v100 = (unsigned int)(v100 + 7);
        }
        while ( v117 < 0 );
      }
      for ( i = 0; i < v115; ++i )
      {
        v119 = v3->CP;
        v120 = *v119;
        v3->CP = v119 + 1;
        v121 = v120 & 0x7F;
        v100 = 7i64;
        if ( v120 < 0 )
        {
          do
          {
            if ( (unsigned int)v100 >= 0x20 )
              break;
            v122 = v3->CP;
            v123 = *v122;
            v3->CP = v122 + 1;
            v121 |= (v123 & 0x7F) << v100;
            v100 = (unsigned int)(v100 + 7);
          }
          while ( v123 < 0 );
        }
        if ( !v121 )
          goto LABEL_149;
      }
      v103 = 1;
    }
    else
    {
LABEL_149:
      v103 = 0;
    }
    v124 = *(_QWORD *)(v104 + 8);
    v125 = v124 + 1;
    if ( v124 + 1 >= v124 )
    {
      if ( v125 > *(_QWORD *)(v104 + 16) )
      {
        v126 = *(void **)v104;
        v132 = v125 + (v125 >> 2);
        if ( !v132 )
          goto LABEL_158;
        v127 = v132 + 3;
LABEL_154:
        v128 = v127 >> 2;
        v129 = 4 * v128;
        v130 = 32 * v128;
        if ( v126 )
        {
          v131 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v126, v130);
        }
        else
        {
          LODWORD(v165) = 339;
          v131 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64, unsigned __int64, unsigned __int64 *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                           Scaleform::Memory::pGlobalHeap,
                           v104,
                           v130,
                           &v165,
                           v162);
        }
        *(_QWORD *)v104 = v131;
        *(_QWORD *)(v104 + 16) = v129;
        v99 = 7;
      }
    }
    else if ( v125 < *(_QWORD *)(v104 + 16) >> 1 )
    {
      v126 = *(void **)v104;
      if ( v124 != -1i64 )
      {
        v127 = v124 + 4;
        goto LABEL_154;
      }
LABEL_158:
      if ( v126 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v126,
          v100);
        *(_QWORD *)v104 = 0i64;
      }
      *(_QWORD *)(v104 + 16) = 0i64;
    }
    *(_QWORD *)(v104 + 8) = v125;
    *(_QWORD *)(*(_QWORD *)v104 + 8 * v125 - 8) = v113;
    if ( --v112 )
      continue;
    break;
  }
  if ( !v103 )
    return 0;
  v77 = cp;
LABEL_168:
  v134 = v3->CP;
  v135 = *v134;
  v3->CP = v134 + 1;
  v136 = v135 & 0x7F;
  if ( v135 < 0 )
  {
    do
    {
      if ( v99 >= 0x20 )
        break;
      v137 = v3->CP;
      v138 = *v137;
      v3->CP = v137 + 1;
      v136 |= (v138 & 0x7F) << v99;
      v99 += 7;
    }
    while ( v138 < 0 );
  }
  v139 = 1;
  v140 = v136 + 1;
  v141 = (void **)&v77->const_multiname.Data.Data;
  if ( v140 > v77->const_multiname.Data.Policy.Capacity )
  {
    v142 = *v141;
    if ( v136 == -1 )
    {
      if ( v142 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v142,
          v100);
        *v141 = 0i64;
      }
      v77->const_multiname.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v143 = (v140 + 3) & 0xFFFFFFFFFFFFFFFCui64;
      v144 = 16 * v143;
      if ( v142 )
      {
        v145 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v142, v144);
      }
      else
      {
        LODWORD(cp) = 339;
        v145 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, Scaleform::GFx::AS3::Abc::ConstPool **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                         Scaleform::Memory::pGlobalHeap,
                         &v77->const_multiname,
                         v144,
                         &cp,
                         v162);
      }
      *v141 = v145;
      v77->const_multiname.Data.Policy.Capacity = v143;
    }
  }
  v146 = v77->const_multiname.Data.Size;
  v147 = v146 + 1;
  if ( v146 + 1 >= v146 )
  {
    if ( v147 > v77->const_multiname.Data.Policy.Capacity )
    {
      v148 = *v141;
      v153 = v147 + (v147 >> 2);
      if ( !v153 )
        goto LABEL_188;
      v149 = v153 + 3;
LABEL_184:
      v150 = v149 & 0xFFFFFFFFFFFFFFFCui64;
      v151 = 16 * v150;
      if ( v148 )
      {
        v152 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v148, v151);
      }
      else
      {
        LODWORD(cp) = 339;
        v152 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, Scaleform::GFx::AS3::Abc::ConstPool **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                         Scaleform::Memory::pGlobalHeap,
                         &v77->const_multiname,
                         v151,
                         &cp,
                         v162);
      }
      *v141 = v152;
      v77->const_multiname.Data.Policy.Capacity = v150;
    }
  }
  else if ( v147 < v77->const_multiname.Data.Policy.Capacity >> 1 )
  {
    v148 = *v141;
    if ( v146 != -1i64 )
    {
      v149 = v146 + 4;
      goto LABEL_184;
    }
LABEL_188:
    if ( v148 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v148,
        v100);
      *v141 = 0i64;
    }
    v77->const_multiname.Data.Policy.Capacity = 0i64;
  }
  v77->const_multiname.Data.Size = v147;
  v154 = (int *)((char *)*v141 + 16 * v147 - 16);
  if ( v154 )
  {
    *v154 = Scaleform::GFx::AS3::Abc::Multiname::AnyType.Ind;
    v154[1] = Scaleform::GFx::AS3::Abc::Multiname::AnyType.NextIndex;
    v154[2] = Scaleform::GFx::AS3::Abc::Multiname::AnyType.NameIndex;
    v154[3] = Scaleform::GFx::AS3::Abc::Multiname::AnyType.Kind;
  }
  if ( v136 > 1 )
  {
    v155 = v136 - 1;
    do
    {
      *(_QWORD *)&obja.Kind = -1i64;
      obja.NameURI.pStr = 0i64;
      v139 = v139 && Scaleform::GFx::AS3::Abc::Reader::Read(v3, v77, (Scaleform::GFx::AS3::Abc::Multiname *)&obja);
      v156 = v77->const_multiname.Data.Size;
      v157 = v156 + 1;
      if ( v156 + 1 >= v156 )
      {
        if ( v157 > v77->const_multiname.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy> *)&v77->const_multiname.Data.Data,
            &v77->const_multiname,
            v157 + (v157 >> 2));
      }
      else if ( v157 < v77->const_multiname.Data.Policy.Capacity >> 1 )
      {
        v158 = *v141;
        if ( v156 == -1i64 )
        {
          if ( v158 )
          {
            ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            *v141 = 0i64;
          }
          v77->const_multiname.Data.Policy.Capacity = 0i64;
        }
        else
        {
          v159 = 16 * ((v156 + 4) & 0xFFFFFFFFFFFFFFFCui64);
          if ( v158 )
          {
            v160 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v158, v159);
          }
          else
          {
            LODWORD(cp) = 339;
            v160 = (void *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::Multiname,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, Scaleform::GFx::AS3::Abc::ConstPool **, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                             Scaleform::Memory::pGlobalHeap,
                             &v77->const_multiname,
                             v159,
                             &cp,
                             v162);
          }
          *v141 = v160;
          v77->const_multiname.Data.Policy.Capacity = (v157 + 3) & 0xFFFFFFFFFFFFFFFCui64;
        }
      }
      v77->const_multiname.Data.Size = v157;
      v161 = (signed __int64)*v141 + 16 * v157 - 16;
      if ( v161 )
      {
        *(_DWORD *)v161 = obja.Kind;
        *(_DWORD *)(v161 + 4) = *((_DWORD *)&obja.Kind + 1);
        *(_QWORD *)(v161 + 8) = obja.NameURI.pStr;
      }
      --v155;
    }
    while ( v155 );
  }
  return v139;
}

// File Line: 355
// RVA: 0x80BD50
char __fastcall Scaleform::GFx::AS3::Abc::Read(const char **ptr, Scaleform::GFx::AS3::Abc::MethodInfo *obj)
{
  const char **v2; // rbx
  Scaleform::GFx::AS3::Abc::MethodInfo *v3; // r12
  char v4; // r8
  char v5; // r15
  unsigned int v6; // ecx
  int v7; // er15
  char v8; // dl
  int v9; // eax
  unsigned int v10; // er8
  char v11; // cl
  char v12; // r9
  int v13; // er9
  char v14; // cl
  char v15; // dl
  __int64 v17; // r14
  unsigned int v18; // er8
  char v19; // cl
  char v20; // bp
  int v21; // ebp
  char v22; // cl
  char v23; // dl
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rdi
  unsigned __int64 v26; // r8
  unsigned int *v27; // rax
  unsigned int v28; // edx
  char v29; // cl
  char v30; // cl
  char v31; // cl
  unsigned int v32; // er8
  char v33; // cl
  char v34; // r14
  int v35; // er14
  char v36; // cl
  char v37; // dl
  int i; // ebp
  unsigned int v39; // er8
  char v40; // cl
  char v41; // r9
  int v42; // er9
  char v43; // cl
  char v44; // dl
  char v45; // cl
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // rdi
  unsigned __int64 v48; // r8
  Scaleform::GFx::AS3::Abc::ValueDetail *v49; // rax
  Scaleform::GFx::AS3::Abc::ValueDetail *v50; // rcx
  __int64 v51; // r14
  unsigned int v52; // er8
  char v53; // cl
  char v54; // bp
  int v55; // ebp
  char v56; // cl
  char v57; // dl
  unsigned __int64 v58; // rax
  unsigned __int64 v59; // rdi
  unsigned __int64 v60; // r8
  int *v61; // rax
  Scaleform::GFx::AS3::Abc::ValueDetail v62; // [rsp+60h] [rbp+18h]

  v2 = ptr;
  v3 = obj;
  v4 = **ptr;
  v5 = *(*ptr)++;
  v6 = 7;
  v7 = v5 & 0x7F;
  if ( v4 < 0 )
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = *(*v2)++;
      v9 = (v8 & 0x7F) << v6;
      v6 += 7;
      v7 |= v9;
    }
    while ( v8 < 0 );
  }
  v10 = 7;
  v11 = **v2;
  v12 = *(*v2)++;
  v13 = v12 & 0x7F;
  if ( v11 < 0 )
  {
    do
    {
      if ( v10 >= 0x20 )
        break;
      v14 = v10;
      v10 += 7;
      v15 = *(*v2)++;
      v13 |= (v15 & 0x7F) << v14;
    }
    while ( v15 < 0 );
  }
  v3->RetTypeInd = v13;
  if ( v13 < 0 )
    return 0;
  if ( v7 > v3->ParamTypes.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->ParamTypes,
      &v3->ParamTypes,
      v7);
  if ( v7 > 0 )
  {
    v17 = (unsigned int)v7;
    do
    {
      v18 = 7;
      v19 = **v2;
      v20 = *(*v2)++;
      v21 = v20 & 0x7F;
      if ( v19 < 0 )
      {
        do
        {
          if ( v18 >= 0x20 )
            break;
          v22 = v18;
          v18 += 7;
          v23 = *(*v2)++;
          v21 |= (v23 & 0x7F) << v22;
        }
        while ( v23 < 0 );
      }
      v24 = v3->ParamTypes.Data.Size;
      v25 = v24 + 1;
      if ( v24 + 1 >= v24 )
      {
        if ( v25 > v3->ParamTypes.Data.Policy.Capacity )
        {
          v26 = v25 + (v25 >> 2);
          goto LABEL_21;
        }
      }
      else if ( v25 < v3->ParamTypes.Data.Policy.Capacity >> 1 )
      {
        v26 = v24 + 1;
LABEL_21:
        Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->ParamTypes,
          &v3->ParamTypes,
          v26);
        goto LABEL_22;
      }
LABEL_22:
      v27 = v3->ParamTypes.Data.Data;
      v3->ParamTypes.Data.Size = v25;
      v27[v25 - 1] = v21;
      --v17;
    }
    while ( v17 );
  }
  v28 = 7;
  v29 = *(*v2)++;
  if ( v29 < 0 )
  {
    do
    {
      if ( v28 >= 0x20 )
        break;
      v28 += 7;
      v30 = *(*v2)++;
    }
    while ( v30 < 0 );
  }
  v31 = *(*v2)++;
  v3->Flags = v31;
  if ( v31 & 8 )
  {
    v32 = 7;
    v33 = **v2;
    v34 = *(*v2)++;
    v35 = v34 & 0x7F;
    if ( v33 < 0 )
    {
      do
      {
        if ( v32 >= 0x20 )
          break;
        v36 = v32;
        v32 += 7;
        v37 = *(*v2)++;
        v35 |= (v37 & 0x7F) << v36;
      }
      while ( v37 < 0 );
    }
    if ( v35 > v3->OptionalParams.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v3->OptionalParams,
        &v3->OptionalParams,
        v35);
    for ( i = 0; ; ++i )
    {
      if ( i >= v35 )
        break;
      v39 = 7;
      v40 = **v2;
      v41 = *(*v2)++;
      v42 = v41 & 0x7F;
      if ( v40 < 0 )
      {
        do
        {
          if ( v39 >= 0x20 )
            break;
          v43 = v39;
          v39 += 7;
          v44 = *(*v2)++;
          v42 |= (v44 & 0x7F) << v43;
        }
        while ( v44 < 0 );
      }
      v62.ValueIndex = v42;
      v45 = *(*v2)++;
      v62.Kind = v45;
      if ( v42 < 0 )
        return 0;
      v46 = v3->OptionalParams.Data.Size;
      v47 = v46 + 1;
      if ( v46 + 1 >= v46 )
      {
        if ( v47 <= v3->OptionalParams.Data.Policy.Capacity )
          goto LABEL_44;
        v48 = v47 + (v47 >> 2);
      }
      else
      {
        if ( v47 >= v3->OptionalParams.Data.Policy.Capacity >> 1 )
          goto LABEL_44;
        v48 = v46 + 1;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v3->OptionalParams,
        &v3->OptionalParams,
        v48);
LABEL_44:
      v49 = v3->OptionalParams.Data.Data;
      v3->OptionalParams.Data.Size = v47;
      v50 = &v49[v47 - 1];
      if ( v50 )
        *v50 = v62;
    }
  }
  if ( v3->Flags < 0 )
  {
    if ( v7 > v3->ParamNames.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->ParamNames.Data.Data,
        &v3->ParamNames,
        v7);
    if ( v7 > 0 )
    {
      v51 = (unsigned int)v7;
      do
      {
        v52 = 7;
        v53 = **v2;
        v54 = *(*v2)++;
        v55 = v54 & 0x7F;
        if ( v53 < 0 )
        {
          do
          {
            if ( v52 >= 0x20 )
              break;
            v56 = v52;
            v52 += 7;
            v57 = *(*v2)++;
            v55 |= (v57 & 0x7F) << v56;
          }
          while ( v57 < 0 );
        }
        v58 = v3->ParamNames.Data.Size;
        v59 = v58 + 1;
        if ( v58 + 1 >= v58 )
        {
          if ( v59 > v3->ParamNames.Data.Policy.Capacity )
          {
            v60 = v59 + (v59 >> 2);
            goto LABEL_61;
          }
        }
        else if ( v59 < v3->ParamNames.Data.Policy.Capacity >> 1 )
        {
          v60 = v58 + 1;
LABEL_61:
          Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->ParamNames.Data.Data,
            &v3->ParamNames,
            v60);
          goto LABEL_62;
        }
LABEL_62:
        v61 = v3->ParamNames.Data.Data;
        v3->ParamNames.Data.Size = v59;
        v61[v59 - 1] = v55;
        --v51;
      }
      while ( v51 );
    }
  }
  return 1;
}ParamNames.Data.Size = v59;
        v61[v59 - 1] = v55;
        --v51;
      }
      while ( v51 );
    }
  }
  return 1;
}

// File Line: 426
// RVA: 0x80D2F0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::MethodTable *obj)
{
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v2; // rbx
  Scaleform::GFx::AS3::Abc::Reader *v3; // r13
  const char *v4; // rax
  char v5; // dl
  int v6; // er14
  unsigned int v7; // ecx
  const char *v8; // rax
  char v9; // dl
  int i; // ebp
  __int64 v11; // rax
  __int64 v12; // rsi
  _QWORD *v13; // rax
  _QWORD *v14; // rax
  _QWORD *v15; // rax
  unsigned __int64 v16; // rax
  unsigned __int64 v17; // rdi
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rcx
  void *v20; // rdi
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // r8
  signed __int64 v25; // [rsp+20h] [rbp-58h]
  signed __int64 v26; // [rsp+28h] [rbp-50h]
  int v27; // [rsp+88h] [rbp+10h]
  __int64 v28; // [rsp+90h] [rbp+18h]
  _QWORD *v29; // [rsp+98h] [rbp+20h]

  v25 = -2i64;
  v2 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v3 = this;
  v4 = this->CP;
  v5 = *v4;
  this->CP = v4 + 1;
  v6 = v5 & 0x7F;
  v7 = 7;
  if ( v5 < 0 )
  {
    do
    {
      if ( v7 >= 0x20 )
        break;
      v8 = v3->CP;
      v9 = *v8;
      v3->CP = v8 + 1;
      v6 |= (v9 & 0x7F) << v7;
      v7 += 7;
    }
    while ( v9 < 0 );
  }
  if ( v6 > v2->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2,
      v2,
      v6);
  for ( i = 0; i < v6; ++i )
  {
    v27 = 338;
    v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, int *, signed __int64, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v3,
            88i64,
            &v27,
            v25,
            v26);
    v12 = v11;
    v28 = v11;
    if ( v11 )
    {
      *(_QWORD *)(v11 + 4) = -1i64;
      v13 = (_QWORD *)(v11 + 16);
      *v13 = 0i64;
      v13[1] = 0i64;
      v13[2] = 0i64;
      v14 = (_QWORD *)(v12 + 40);
      *v14 = 0i64;
      v14[1] = 0i64;
      v14[2] = 0i64;
      v15 = (_QWORD *)(v12 + 64);
      v29 = v15;
      v26 = v12 + 64;
      *v15 = 0i64;
      v15[1] = 0i64;
      v15[2] = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    v16 = v2->Size;
    v17 = v16 + 1;
    if ( v16 + 1 >= v16 )
    {
      if ( v17 <= v2->Policy.Capacity )
        goto LABEL_17;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= v2->Policy.Capacity >> 1 )
        goto LABEL_17;
      v18 = v16 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v2,
      v2,
      v18);
LABEL_17:
    v2->Size = v17;
    v2->Data[v17 - 1] = v12;
    if ( !Scaleform::GFx::AS3::Abc::Read(&v3->CP, (Scaleform::GFx::AS3::Abc::MethodInfo *)v2->Data[v2->Size - 1]) )
    {
      v19 = v2->Size;
      v20 = (void *)v2->Data[v19 - 1];
      if ( v20 )
      {
        Scaleform::GFx::AS3::Abc::MethodInfo::~MethodInfo((Scaleform::GFx::AS3::Abc::MethodInfo *)v2->Data[v19 - 1]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20);
      }
      v21 = v2->Size;
      v22 = v21 - 1;
      if ( v21 - 1 >= v21 )
      {
        if ( v22 > v2->Policy.Capacity )
        {
          v23 = v22 + (v22 >> 2);
LABEL_26:
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v2,
            v2,
            v23);
        }
      }
      else if ( v22 < v2->Policy.Capacity >> 1 )
      {
        v23 = v21 - 1;
        goto LABEL_26;
      }
      v2->Size = v22;
      return 0;
    }
  }
  return 1;
}

// File Line: 451
// RVA: 0x80E0E0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *cp, Scaleform::GFx::AS3::Abc::MetadataInfo *obj)
{
  __int64 v3; // rbp
  Scaleform::GFx::AS3::Abc::MetadataInfo *v4; // r14
  Scaleform::GFx::AS3::Abc::Reader *v5; // rbx
  const char *v6; // rax
  char v7; // cl
  unsigned int v8; // er8
  __int64 v9; // rsi
  const char *v10; // rax
  char v11; // cl
  char v12; // dl
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v13; // r14
  __int64 v14; // r15
  char v15; // di
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v16; // r9
  char v17; // dl
  unsigned int v18; // ecx
  int v19; // er8
  char v20; // dl
  int v21; // eax
  signed __int64 v22; // r9
  const char *v23; // rax
  unsigned int v24; // ecx
  char v25; // dl
  int v26; // er8
  char v27; // dl
  int v28; // eax
  Scaleform::StringDataPtr zero_val; // [rsp+20h] [rbp-28h]

  v3 = 0i64;
  v4 = obj;
  v5 = this;
  zero_val.pStr = 0i64;
  zero_val.Size = 0i64;
  if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->Name, &zero_val) )
    return 0;
  v6 = v5->CP;
  v7 = *v6;
  v5->CP = v6 + 1;
  v8 = 7;
  v9 = v7 & 0x7F;
  if ( v7 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = v5->CP;
      v11 = v8;
      v8 += 7;
      v12 = *v10;
      v5->CP = v10 + 1;
      v9 = ((v12 & 0x7F) << v11) | (unsigned int)v9;
    }
    while ( v12 < 0 );
  }
  v13 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&v4->Items;
  v14 = (signed int)v9;
  v15 = 1;
  if ( (signed int)v9 > v13->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v13,
      v13,
      (signed int)v9);
  if ( (signed int)v9 > 0 )
  {
    do
    {
      v16 = Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>>::PushDefault((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> > *)v13);
      if ( v15 )
      {
        v17 = *v5->CP++;
        v18 = 7;
        v19 = v17 & 0x7F;
        if ( v17 < 0 )
        {
          do
          {
            if ( v18 >= 0x20 )
              break;
            v20 = *v5->CP++;
            v21 = (v20 & 0x7F) << v18;
            v18 += 7;
            v19 |= v21;
          }
          while ( v20 < 0 );
        }
        v16->KeyInd = v19;
        v15 = 1;
      }
      else
      {
        v15 = 0;
      }
      --v9;
    }
    while ( v9 );
  }
  if ( v14 > 0 )
  {
    do
    {
      v22 = (signed __int64)&v13->Data[v3];
      if ( v15 )
      {
        v23 = v5->CP;
        v24 = 7;
        v25 = *v23;
        v5->CP = v23 + 1;
        v26 = v25 & 0x7F;
        if ( v25 < 0 )
        {
          do
          {
            if ( v24 >= 0x20 )
              break;
            v27 = *v5->CP++;
            v28 = (v27 & 0x7F) << v24;
            v24 += 7;
            v26 |= v28;
          }
          while ( v27 < 0 );
        }
        *(_DWORD *)(v22 + 4) = v26;
        v15 = 1;
      }
      else
      {
        v15 = 0;
      }
      ++v3;
    }
    while ( v3 < v14 );
  }
  return v15;
}

// File Line: 497
// RVA: 0x80E280
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::ConstPool *cp, Scaleform::GFx::AS3::Abc::MetadataTable *obj)
{
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::Abc::ConstPool *v4; // r12
  Scaleform::GFx::AS3::Abc::Reader *v5; // r15
  const char *v6; // rax
  char v7; // r8
  int v8; // ebp
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  int v12; // er14
  _QWORD *v13; // rax
  _QWORD *v14; // rsi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  void **v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  signed __int64 v23; // [rsp+20h] [rbp-58h]
  _QWORD *v24; // [rsp+28h] [rbp-50h]
  _QWORD *v25; // [rsp+30h] [rbp-48h]
  _QWORD *v26; // [rsp+38h] [rbp-40h]
  void **v27; // [rsp+98h] [rbp+20h]

  v23 = -2i64;
  v3 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v4 = cp;
  v5 = this;
  v6 = this->CP;
  v7 = *v6;
  this->CP = v6 + 1;
  v8 = v7 & 0x7F;
  v9 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v10 = v5->CP;
      v11 = *v10;
      v5->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > v3->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v3,
      v3,
      v8);
  v12 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v27) = 338;
    v13 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, void ***, signed __int64, _QWORD *, _QWORD *, _QWORD *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                      Scaleform::Memory::pGlobalHeap,
                      v5,
                      40i64,
                      &v27,
                      v23,
                      v24,
                      v25,
                      v26);
    v14 = v13;
    v24 = v13;
    if ( v13 )
    {
      *v13 = 0i64;
      v13[1] = 0i64;
      v25 = v13 + 2;
      v26 = v25;
      *v25 = 0i64;
      v25[1] = 0i64;
      v25[2] = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = v3->Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= v3->Policy.Capacity )
        goto LABEL_16;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= v3->Policy.Capacity >> 1 )
        goto LABEL_16;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v3,
      v3,
      v17);
LABEL_16:
    v3->Size = v16;
    v3->Data[v16 - 1] = (unsigned __int64)v14;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            v5,
            v4,
            (Scaleform::GFx::AS3::Abc::MetadataInfo *)v3->Data[v3->Size - 1]) )
      break;
    if ( ++v12 >= v8 )
      return 1;
  }
  v18 = (void **)v3->Data[v3->Size - 1];
  v27 = v18;
  if ( v18 )
  {
    v27 = v18 + 2;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18[2]);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
  }
  v19 = v3->Size;
  v20 = v19 - 1;
  if ( v19 - 1 >= v19 )
  {
    if ( v20 > v3->Policy.Capacity )
    {
      v21 = v20 + (v20 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v3,
        v3,
        v21);
    }
  }
  else if ( v20 < v3->Policy.Capacity >> 1 )
  {
    v21 = v19 - 1;
    goto LABEL_26;
  }
  v3->Size = v20;
  return 0;
}

// File Line: 525
// RVA: 0x80D500
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitInfo *obj)
{
  const char *v2; // rax
  unsigned int v3; // ebx
  Scaleform::GFx::AS3::Abc::Reader *v4; // rdi
  char v5; // r8
  Scaleform::GFx::AS3::Abc::TraitInfo *v6; // rsi
  unsigned int v7; // ecx
  int v8; // er9
  char v9; // dl
  int v10; // eax
  const char *v11; // rax
  char v12; // cl
  bool v13; // sf
  bool result; // al
  char v15; // cl
  int v16; // ebp
  const char *v17; // rax
  char v18; // cl
  char v19; // dl
  bool v20; // cl
  char *v21; // rax
  char v22; // bl
  char v23; // al
  Scaleform::GFx::AS3::Abc::ValueDetail v24; // [rsp+50h] [rbp+18h]

  v2 = this->CP;
  v3 = 7;
  v4 = this;
  v5 = *v2;
  v6 = obj;
  this->CP = v2 + 1;
  v7 = 7;
  v8 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v7 >= 0x20 )
        break;
      v9 = *v4->CP++;
      v10 = (v9 & 0x7F) << v7;
      v7 += 7;
      v8 |= v10;
    }
    while ( v9 < 0 );
  }
  v6->name_ind = v8;
  v11 = v4->CP;
  v12 = *v11;
  v4->CP = v11 + 1;
  v13 = v6->name_ind < 0;
  v6->kind = v12;
  if ( v13 )
    return 0;
  switch ( v12 & 0xF )
  {
    case 0:
    case 6:
      if ( Scaleform::GFx::AS3::Abc::Reader::Read(v4, (unsigned int *)&v6->SlotId)
        && Scaleform::GFx::AS3::Abc::Reader::Read(v4, (unsigned int *)&v6->Ind) )
      {
        v15 = *v4->CP++;
        v16 = v15 & 0x7F;
        if ( v15 < 0 )
        {
          do
          {
            if ( v3 >= 0x20 )
              break;
            v17 = v4->CP;
            v18 = v3;
            v3 += 7;
            v19 = *v17;
            v4->CP = v17 + 1;
            v16 |= (v19 & 0x7F) << v18;
          }
          while ( v19 < 0 );
        }
        v20 = 1;
        if ( !v16 )
          goto LABEL_22;
        v21 = (char *)v4->CP;
        v22 = *v21;
        v4->CP = v21 + 1;
        v23 = Scaleform::GFx::AS3::Abc::IsValidValueKind(v22);
        v20 = 1;
        v24.Kind = v22;
        v24.ValueIndex = v16;
        if ( !v23 )
          v20 = 0;
        v6->default_value = v24;
        if ( v20 )
          goto LABEL_22;
      }
      goto LABEL_16;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(v4, (unsigned int *)&v6->SlotId)
        || !Scaleform::GFx::AS3::Abc::Reader::Read(v4, (unsigned int *)&v6->Ind)
        || v6->SlotId < 0
        || v6->Ind < 0 )
      {
        goto LABEL_16;
      }
      v20 = 1;
LABEL_22:
      if ( v6->kind & 0x40 )
        v20 = Scaleform::GFx::AS3::Abc::Reader::Read(v4, &v6->meta_info) != 0;
      result = v20;
      break;
    default:
LABEL_16:
      result = 0;
      break;
  }
  return result;
}

// File Line: 645
// RVA: 0x80F190
char __fastcall Scaleform::GFx::AS3::Abc::Reader::ReadTraits(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *obj_traits)
{
  Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *v3; // rdi
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v4; // rbx
  Scaleform::GFx::AS3::Abc::Reader *v5; // r15
  const char *v6; // rax
  char v7; // r9
  int v8; // er14
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  unsigned __int64 v12; // r8
  int v13; // er12
  unsigned __int64 v14; // rbp
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  __int64 v18; // rax
  __int64 v19; // rbp
  _QWORD *v20; // rax
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rsi
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // r8
  void **v27; // rdi
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rdi
  unsigned __int64 v30; // r8
  signed __int64 v32; // [rsp+20h] [rbp-68h]
  _QWORD *v33; // [rsp+28h] [rbp-60h]
  _QWORD *v34; // [rsp+30h] [rbp-58h]
  void **v35; // [rsp+98h] [rbp+10h]
  __int64 v36; // [rsp+A0h] [rbp+18h]
  _QWORD *v37; // [rsp+A8h] [rbp+20h]

  v32 = -2i64;
  v3 = obj_traits;
  v4 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)t;
  v5 = this;
  v6 = this->CP;
  v7 = *v6;
  this->CP = v6 + 1;
  v8 = v7 & 0x7F;
  v9 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v10 = v5->CP;
      v11 = *v10;
      v5->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > obj_traits->Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&obj_traits->Data.Data,
      obj_traits,
      v8);
  v12 = v8 + v4->Size;
  if ( v12 > v4->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v4,
      v4,
      v12);
  v13 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    v14 = v4->Size;
    v15 = v3->Data.Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= v3->Data.Policy.Capacity )
        goto LABEL_15;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= v3->Data.Policy.Capacity >> 1 )
        goto LABEL_15;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->Data.Data,
      v3,
      v17);
LABEL_15:
    v3->Data.Size = v16;
    v3->Data.Data[v16 - 1] = v14;
    LODWORD(v35) = 338;
    v18 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, void ***, signed __int64, _QWORD *, _QWORD *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v5,
            48i64,
            &v35,
            v32,
            v33,
            v34);
    v19 = v18;
    v36 = v18;
    if ( v18 )
    {
      *(_QWORD *)(v18 + 4) = -1i64;
      *(_DWORD *)(v18 + 12) = -1;
      *(_BYTE *)(v18 + 16) = 0;
      *(_DWORD *)(v18 + 20) = -1;
      v20 = (_QWORD *)(v18 + 24);
      v37 = v20;
      v33 = v20;
      v34 = v20;
      *v20 = 0i64;
      v20[1] = 0i64;
      v20[2] = 0i64;
    }
    else
    {
      v19 = 0i64;
    }
    v21 = v4->Size;
    v22 = v21 + 1;
    if ( v21 + 1 >= v21 )
    {
      if ( v22 <= v4->Policy.Capacity )
        goto LABEL_24;
      v23 = v22 + (v22 >> 2);
    }
    else
    {
      if ( v22 >= v4->Policy.Capacity >> 1 )
        goto LABEL_24;
      v23 = v21 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v4,
      v4,
      v23);
LABEL_24:
    v4->Size = v22;
    v4->Data[v22 - 1] = v19;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(v5, (Scaleform::GFx::AS3::Abc::TraitInfo *)v4->Data[v4->Size - 1]) )
      break;
    if ( ++v13 >= v8 )
      return 1;
  }
  v24 = v3->Data.Size;
  v25 = v24 - 1;
  if ( v24 - 1 >= v24 )
  {
    if ( v25 > v3->Data.Policy.Capacity )
    {
      v26 = v25 + (v25 >> 2);
LABEL_32:
      Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v3->Data.Data,
        v3,
        v26);
    }
  }
  else if ( v25 < v3->Data.Policy.Capacity >> 1 )
  {
    v26 = v24 - 1;
    goto LABEL_32;
  }
  v3->Data.Size = v25;
  v27 = (void **)v4->Data[v4->Size - 1];
  v35 = v27;
  if ( v27 )
  {
    v35 = v27 + 3;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27[3]);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27);
  }
  v28 = v4->Size;
  v29 = v28 - 1;
  if ( v28 - 1 >= v28 )
  {
    if ( v29 > v4->Policy.Capacity )
    {
      v30 = v29 + (v29 >> 2);
LABEL_40:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v4,
        v4,
        v30);
    }
  }
  else if ( v29 < v4->Policy.Capacity >> 1 )
  {
    v30 = v28 - 1;
    goto LABEL_40;
  }
  v4->Size = v29;
  return 0;
}

// File Line: 679
// RVA: 0x80D9B0
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::HasCode *obj)
{
  const char *v3; // rax
  Scaleform::GFx::AS3::Abc::Reader *v4; // r10
  Scaleform::GFx::AS3::Abc::HasCode *v5; // rbx
  char v6; // r9
  Scaleform::GFx::AS3::Abc::TraitTable *v7; // rdi
  unsigned int v8; // ecx
  int v9; // er11
  char v10; // dl
  int v11; // eax

  v3 = this->CP;
  v4 = this;
  v5 = obj;
  v6 = *v3;
  v7 = t;
  this->CP = v3 + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *v4->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  obj->method_info_ind = v9;
  return Scaleform::GFx::AS3::Abc::Reader::ReadTraits(v4, v7, &obj->obj_traits) && v5->method_info_ind >= 0;
}

// File Line: 693
// RVA: 0x80DA40
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::Instance *obj)
{
  const char *v3; // rax
  Scaleform::GFx::AS3::Abc::Instance *v4; // rdi
  Scaleform::GFx::AS3::Abc::Reader *v5; // rbx
  char v6; // r9
  Scaleform::GFx::AS3::Abc::TraitTable *v7; // rbp
  unsigned int v8; // ecx
  int v9; // er8
  char v10; // dl
  int v11; // eax
  char v12; // cl
  bool v13; // sf
  bool v14; // al

  v3 = this->CP;
  v4 = obj;
  v5 = this;
  v6 = *v3;
  v7 = t;
  this->CP = v3 + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *v5->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  v4->name_ind = v9;
  v14 = 0;
  if ( Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->super_name_ind) )
  {
    v12 = *v5->CP++;
    v13 = v4->name_ind < 0;
    v4->flags = v12;
    if ( !v13 && v4->super_name_ind >= 0 )
      v14 = 1;
  }
  if ( v4->flags & 8 )
  {
    if ( !v14 || !Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->protected_namespace_ind) )
      return 0;
  }
  else if ( !v14 )
  {
    return 0;
  }
  if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
          v5,
          (Scaleform::GFx::AS3::Abc::TraitInfo::MetaInfo *)&v4->implemented_interfaces)
    || !Scaleform::GFx::AS3::Abc::Reader::Read(v5, v7, (Scaleform::GFx::AS3::Abc::HasCode *)&v4->obj_traits) )
  {
    return 0;
  }
  return 1;
}

// File Line: 716
// RVA: 0x80D1C0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitInfo::MetaInfo *obj)
{
  const char *v2; // rax
  Scaleform::GFx::AS3::Abc::Reader *v3; // rbp
  Scaleform::GFx::AS3::Abc::TraitInfo::MetaInfo *v4; // rdi
  char v5; // r8
  unsigned int v6; // ecx
  int v7; // ebx
  char v8; // dl
  int v9; // eax
  __int64 v10; // r14
  const char *v11; // rax
  unsigned int v12; // ecx
  char v13; // dl
  int v14; // esi
  char v15; // dl
  int v16; // eax
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  int *v20; // rax

  v2 = this->CP;
  v3 = this;
  v4 = obj;
  v5 = *v2;
  this->CP = v2 + 1;
  v6 = 7;
  v7 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = *v3->CP++;
      v9 = (v8 & 0x7F) << v6;
      v6 += 7;
      v7 |= v9;
    }
    while ( v8 < 0 );
  }
  if ( v7 > v4->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v4->info.Data.Data,
      v4,
      v7);
  if ( v7 > 0 )
  {
    v10 = (unsigned int)v7;
    do
    {
      v11 = v3->CP;
      v12 = 7;
      v13 = *v11;
      v3->CP = v11 + 1;
      v14 = v13 & 0x7F;
      if ( v13 < 0 )
      {
        do
        {
          if ( v12 >= 0x20 )
            break;
          v15 = *v3->CP++;
          v16 = (v15 & 0x7F) << v12;
          v12 += 7;
          v14 |= v16;
        }
        while ( v15 < 0 );
      }
      v17 = v4->info.Data.Size;
      v18 = v17 + 1;
      if ( v17 + 1 >= v17 )
      {
        if ( v18 > v4->info.Data.Policy.Capacity )
        {
          v19 = v18 + (v18 >> 2);
          goto LABEL_16;
        }
      }
      else if ( v18 < v4->info.Data.Policy.Capacity >> 1 )
      {
        v19 = v17 + 1;
LABEL_16:
        Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&v4->info.Data.Data,
          v4,
          v19);
        goto LABEL_17;
      }
LABEL_17:
      v20 = v4->info.Data.Data;
      v4->info.Data.Size = v18;
      v20[v18 - 1] = v14;
      --v10;
    }
    while ( v10 );
  }
  return 1;
}

// File Line: 739
// RVA: 0x80D6E0
__int64 __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::ClassTable *obj)
{
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v3; // r14
  Scaleform::GFx::AS3::Abc::Reader *v4; // rsi
  const char *v5; // rax
  char v6; // r9
  int v7; // er15
  unsigned int v8; // ecx
  const char *v9; // rax
  char v10; // dl
  unsigned __int8 v11; // bl
  signed __int64 v12; // rdi
  int i; // er12
  __int64 v14; // rax
  __int64 v15; // rbx
  _QWORD *v16; // ST40_8
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rbp
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rcx
  void *v21; // rbp
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rbp
  unsigned __int64 v24; // r8
  unsigned __int64 v25; // rbp
  const char *v26; // rax
  char v27; // dl
  int v28; // er8
  unsigned int v29; // ecx
  const char *v30; // rax
  char v31; // dl
  signed __int64 v33; // [rsp+20h] [rbp-78h]
  __int64 v34; // [rsp+28h] [rbp-70h]
  signed __int64 v35; // [rsp+30h] [rbp-68h]
  signed __int64 v36; // [rsp+38h] [rbp-60h]
  _QWORD *v37; // [rsp+40h] [rbp-58h]
  Scaleform::GFx::AS3::Abc::TraitTable *ta; // [rsp+A8h] [rbp+10h]
  int v39; // [rsp+B0h] [rbp+18h]
  __int64 v40; // [rsp+B8h] [rbp+20h]

  ta = t;
  v33 = -2i64;
  v3 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v4 = this;
  v5 = this->CP;
  v6 = *v5;
  this->CP = v5 + 1;
  v7 = v6 & 0x7F;
  v8 = 7;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v9 = v4->CP;
      v10 = *v9;
      v4->CP = v9 + 1;
      v7 |= (v10 & 0x7F) << v8;
      v8 += 7;
    }
    while ( v10 < 0 );
  }
  v11 = 1;
  if ( v7 > obj->Info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj,
      obj,
      v7);
  v12 = 0i64;
  for ( i = 0; i < v7; ++i )
  {
    v39 = 338;
    v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, int *, signed __int64, __int64, signed __int64, signed __int64, _QWORD *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v4,
            104i64,
            &v39,
            v33,
            v34,
            v35,
            v36,
            v37);
    v15 = v14;
    v40 = v14;
    if ( v14 )
    {
      v34 = v14;
      *(_QWORD *)v14 = 0i64;
      *(_QWORD *)(v14 + 8) = 0i64;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_DWORD *)(v14 + 24) = -1;
      *(_QWORD *)(v14 + 36) = -1i64;
      *(_DWORD *)(v14 + 44) = -1;
      v16 = (_QWORD *)(v14 + 48);
      *v16 = 0i64;
      v16[1] = 0i64;
      v16[2] = 0i64;
      v37 = (_QWORD *)(v14 + 72);
      v36 = v14 + 72;
      v35 = v14 + 72;
      *v37 = 0i64;
      v37[1] = 0i64;
      v37[2] = 0i64;
      *(_DWORD *)(v14 + 96) = -1;
    }
    else
    {
      v15 = 0i64;
    }
    v17 = v3->Size;
    v18 = v17 + 1;
    if ( v17 + 1 >= v17 )
    {
      if ( v18 <= v3->Policy.Capacity )
        goto LABEL_17;
      v19 = v18 + (v18 >> 2);
    }
    else
    {
      if ( v18 >= v3->Policy.Capacity >> 1 )
        goto LABEL_17;
      v19 = v17 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v3,
      v3,
      v19);
LABEL_17:
    v3->Size = v18;
    v3->Data[v18 - 1] = v15;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(v4, ta, (Scaleform::GFx::AS3::Abc::Instance *)v3->Data[v3->Size - 1]) )
    {
      v11 = 0;
      v20 = v3->Size;
      v21 = (void *)v3->Data[v20 - 1];
      if ( v21 )
      {
        Scaleform::GFx::AS3::Abc::ClassInfo::~ClassInfo((Scaleform::GFx::AS3::Abc::ClassInfo *)v3->Data[v20 - 1]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
      }
      v22 = v3->Size;
      v23 = v22 - 1;
      if ( v22 - 1 >= v22 )
      {
        if ( v23 > v3->Policy.Capacity )
        {
          v24 = v23 + (v23 >> 2);
LABEL_26:
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v3,
            v3,
            v24);
        }
      }
      else if ( v23 < v3->Policy.Capacity >> 1 )
      {
        v24 = v22 - 1;
        goto LABEL_26;
      }
      v3->Size = v23;
      break;
    }
    v11 = 1;
  }
  while ( v11 )
  {
    if ( v12 >= v7 )
      break;
    v25 = v3->Data[v12++];
    if ( !v11 )
      goto LABEL_42;
    v26 = v4->CP;
    v27 = *v26;
    v4->CP = v26 + 1;
    v28 = v27 & 0x7F;
    v29 = 7;
    if ( v27 < 0 )
    {
      do
      {
        if ( v29 >= 0x20 )
          break;
        v30 = v4->CP;
        v31 = *v30;
        v4->CP = v30 + 1;
        v28 |= (v31 & 0x7F) << v29;
        v29 += 7;
      }
      while ( v31 < 0 );
    }
    *(_DWORD *)(v25 + 96) = v28;
    if ( Scaleform::GFx::AS3::Abc::Reader::ReadTraits(
           v4,
           ta,
           (Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *)(v25 + 72))
      && *(_DWORD *)(v25 + 96) >= 0 )
    {
      v11 = 1;
    }
    else
    {
LABEL_42:
      v11 = 0;
    }
  }
  return v11;
}

// File Line: 806
// RVA: 0x80DED0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::ScriptTable *obj)
{
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v3; // rbx
  Scaleform::GFx::AS3::Abc::TraitTable *v4; // r12
  Scaleform::GFx::AS3::Abc::Reader *v5; // r14
  const char *v6; // rax
  char v7; // r8
  int v8; // ebp
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  int v12; // er15
  __int64 v13; // rax
  __int64 v14; // rdi
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  void **v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  signed __int64 v23; // [rsp+20h] [rbp-58h]
  __int64 v24; // [rsp+28h] [rbp-50h]
  __int64 v25; // [rsp+30h] [rbp-48h]
  void **v26; // [rsp+90h] [rbp+18h]
  __int64 v27; // [rsp+98h] [rbp+20h]

  v23 = -2i64;
  v3 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v4 = t;
  v5 = this;
  v6 = this->CP;
  v7 = *v6;
  this->CP = v6 + 1;
  v8 = v7 & 0x7F;
  v9 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v10 = v5->CP;
      v11 = *v10;
      v5->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > v3->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v3,
      v3,
      v8);
  v12 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v26) = 338;
    v13 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, void ***, signed __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v5,
            32i64,
            &v26,
            v23,
            v24,
            v25);
    v14 = v13;
    v27 = v13;
    if ( v13 )
    {
      v24 = v13;
      v25 = v13;
      *(_QWORD *)v13 = 0i64;
      *(_QWORD *)(v13 + 8) = 0i64;
      *(_QWORD *)(v13 + 16) = 0i64;
      *(_DWORD *)(v13 + 24) = -1;
    }
    else
    {
      v14 = 0i64;
    }
    v15 = v3->Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= v3->Policy.Capacity )
        goto LABEL_16;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= v3->Policy.Capacity >> 1 )
        goto LABEL_16;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v3,
      v3,
      v17);
LABEL_16:
    v3->Size = v16;
    v3->Data[v16 - 1] = v14;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(v5, v4, (Scaleform::GFx::AS3::Abc::HasCode *)v3->Data[v3->Size - 1]) )
      break;
    if ( ++v12 >= v8 )
      return 1;
  }
  v18 = (void **)v3->Data[v3->Size - 1];
  v26 = v18;
  if ( v18 )
  {
    v26 = v18;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *v18);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
  }
  v19 = v3->Size;
  v20 = v19 - 1;
  if ( v19 - 1 >= v19 )
  {
    if ( v20 > v3->Policy.Capacity )
    {
      v21 = v20 + (v20 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v3,
        v3,
        v21);
    }
  }
  else if ( v20 < v3->Policy.Capacity >> 1 )
  {
    v21 = v19 - 1;
    goto LABEL_26;
  }
  v3->Size = v20;
  return 0;
}

// File Line: 831
// RVA: 0x80C1D0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::Code *obj)
{
  Scaleform::GFx::AS3::Abc::Reader *v2; // r8
  const char *v3; // rax
  char v4; // dl
  unsigned int v5; // ecx
  int v6; // er9
  char v7; // dl
  int v8; // eax

  v2 = this;
  obj->code.Data = this->CP;
  v3 = this->CP;
  v4 = *v3;
  this->CP = v3 + 1;
  v5 = 7;
  v6 = v4 & 0x7F;
  if ( v4 < 0 )
  {
    do
    {
      if ( v5 >= 0x20 )
        break;
      v7 = *v2->CP++;
      v8 = (v7 & 0x7F) << v5;
      v5 += 7;
      v6 |= v8;
    }
    while ( v7 < 0 );
  }
  v2->CP += v6;
  return 1;
}

// File Line: 844
// RVA: 0x80DB40
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::MethodBodyInfo *obj)
{
  const char *v3; // rax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v4; // rdi
  Scaleform::GFx::AS3::Abc::Reader *v5; // rbx
  char v6; // r9
  Scaleform::GFx::AS3::Abc::TraitTable *v7; // rsi
  unsigned int v8; // ecx
  int v9; // er8
  char v10; // dl
  int v11; // eax

  v3 = this->CP;
  v4 = obj;
  v5 = this;
  v6 = *v3;
  v7 = t;
  this->CP = v3 + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *v5->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  v4->method_info_ind = v9;
  return Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->max_stack)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->local_reg_count)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->init_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v5, (unsigned int *)&v4->max_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v5, &v4->code)
      && Scaleform::GFx::AS3::Abc::Reader::Read(v5, &v4->exception)
      && Scaleform::GFx::AS3::Abc::Reader::ReadTraits(v5, v7, &v4->obj_traits)
      && v4->method_info_ind >= 0;
}

// File Line: 878
// RVA: 0x80CE90
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *obj)
{
  const char *v2; // rax
  Scaleform::GFx::AS3::Abc::Reader *v3; // rbx
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *v4; // rsi
  char v5; // cl
  unsigned int v6; // er8
  int v7; // ebp
  const char *v8; // rax
  char v9; // cl
  char v10; // dl
  int v11; // er14
  const char *v12; // rax
  char v13; // cl
  unsigned int v14; // er8
  int v15; // er9
  const char *v16; // rax
  char v17; // cl
  char v18; // dl
  const char *v19; // rax
  unsigned int v20; // er8
  char v21; // cl
  int v22; // er9
  const char *v23; // rax
  char v24; // cl
  char v25; // dl
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // rdi
  unsigned __int64 v28; // r8
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v29; // rax
  signed __int64 v30; // rdx
  int v32; // [rsp+20h] [rbp-38h]
  int v33; // [rsp+24h] [rbp-34h]
  unsigned int v[2]; // [rsp+28h] [rbp-30h]
  unsigned int v35; // [rsp+30h] [rbp-28h]

  v2 = this->CP;
  v3 = this;
  v4 = obj;
  v5 = *v2;
  v6 = 7;
  v3->CP = v2 + 1;
  v7 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = v3->CP;
      v9 = v6;
      v6 += 7;
      v10 = *v8;
      v3->CP = v8 + 1;
      v7 |= (v10 & 0x7F) << v9;
    }
    while ( v10 < 0 );
  }
  if ( v7 > v4->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy> *)&v4->info.Data.Data,
      v4,
      v7);
  v11 = 0;
  while ( v11 < v7 )
  {
    v12 = v3->CP;
    *(_QWORD *)v = 0i64;
    v35 = 0;
    v13 = *v12;
    v14 = 7;
    v3->CP = v12 + 1;
    v15 = v13 & 0x7F;
    if ( v13 < 0 )
    {
      do
      {
        if ( v14 >= 0x20 )
          break;
        v16 = v3->CP;
        v17 = v14;
        v14 += 7;
        v18 = *v16;
        v3->CP = v16 + 1;
        v15 |= (v18 & 0x7F) << v17;
      }
      while ( v18 < 0 );
    }
    v19 = v3->CP;
    v32 = v15;
    v20 = 7;
    v21 = *v19;
    v3->CP = v19 + 1;
    v22 = v21 & 0x7F;
    if ( v21 < 0 )
    {
      do
      {
        if ( v20 >= 0x20 )
          break;
        v23 = v3->CP;
        v24 = v20;
        v20 += 7;
        v25 = *v23;
        v3->CP = v23 + 1;
        v22 |= (v25 & 0x7F) << v24;
      }
      while ( v25 < 0 );
    }
    v33 = v22;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(v3, v)
      || !Scaleform::GFx::AS3::Abc::Reader::Read(v3, &v[1])
      || !Scaleform::GFx::AS3::Abc::Reader::Read(v3, &v35) )
    {
      return 0;
    }
    v26 = v4->info.Data.Size;
    v27 = v26 + 1;
    if ( v26 + 1 >= v26 )
    {
      if ( v27 <= v4->info.Data.Policy.Capacity )
        goto LABEL_23;
      v28 = v27 + (v27 >> 2);
    }
    else
    {
      if ( v27 >= v4->info.Data.Policy.Capacity >> 1 )
        goto LABEL_23;
      v28 = v26 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy> *)&v4->info.Data.Data,
      v4,
      v28);
LABEL_23:
    v29 = v4->info.Data.Data;
    v4->info.Data.Size = v27;
    v30 = (signed __int64)&v29[v27];
    ++v11;
    *(_DWORD *)(v30 - 20) = v32;
    *(_DWORD *)(v30 - 16) = v33;
    *(_DWORD *)(v30 - 12) = v[0];
    *(_DWORD *)(v30 - 8) = v[1];
    *(_DWORD *)(v30 - 4) = v35;
  }
  return 1;
}ORD *)(v30 - 16) = v33;
    *(_DWORD *)(v30 - 12) = v[0];
    *(_DWORD *)(v30

// File Line: 900
// RVA: 0x80DC40
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(Scaleform::GFx::AS3::Abc::Reader *this, Scaleform::GFx::AS3::Abc::TraitTable *t, Scaleform::GFx::AS3::Abc::MethodTable *mt, Scaleform::GFx::AS3::Abc::MethodBodyTable *obj)
{
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *v4; // rbx
  Scaleform::GFx::AS3::Abc::MethodTable *v5; // r12
  Scaleform::GFx::AS3::Abc::TraitTable *v6; // r13
  Scaleform::GFx::AS3::Abc::Reader *v7; // r14
  const char *v8; // rax
  char v9; // r10
  int v10; // ebp
  unsigned int v11; // ecx
  const char *v12; // rax
  char v13; // dl
  int v14; // er15
  __int64 v15; // rax
  __int64 v16; // rdi
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rsi
  unsigned __int64 v19; // r8
  unsigned __int64 v20; // rdi
  __int64 v21; // rdi
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rdi
  unsigned __int64 v24; // r8
  signed __int64 v26; // [rsp+20h] [rbp-68h]
  __int64 v27; // [rsp+28h] [rbp-60h]
  signed __int64 v28; // [rsp+30h] [rbp-58h]
  _QWORD *v29; // [rsp+38h] [rbp-50h]
  signed __int64 v30; // [rsp+40h] [rbp-48h]
  __int64 v31; // [rsp+A8h] [rbp+20h]

  v26 = -2i64;
  v4 = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj;
  v5 = mt;
  v6 = t;
  v7 = this;
  v8 = this->CP;
  v9 = *v8;
  this->CP = v8 + 1;
  v10 = v9 & 0x7F;
  v11 = 7;
  if ( v9 < 0 )
  {
    do
    {
      if ( v11 >= 0x20 )
        break;
      v12 = v7->CP;
      v13 = *v12;
      v7->CP = v12 + 1;
      v10 |= (v13 & 0x7F) << v11;
      v11 += 7;
    }
    while ( v13 < 0 );
  }
  if ( v10 > obj->Info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)obj,
      obj,
      v10);
  v14 = 0;
  if ( v10 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v31) = 338;
    v15 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, signed __int64, __int64 *, signed __int64, __int64, signed __int64, _QWORD *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            v7,
            88i64,
            &v31,
            v26,
            v27,
            v28,
            v29,
            v30);
    v16 = v15;
    v27 = v15;
    if ( v15 )
    {
      *(_QWORD *)v15 = 0i64;
      *(_QWORD *)(v15 + 8) = 0i64;
      *(_QWORD *)(v15 + 16) = 0i64;
      *(_QWORD *)(v15 + 24) = -1i64;
      *(_QWORD *)(v15 + 32) = -1i64;
      *(_DWORD *)(v15 + 40) = -1;
      *(_QWORD *)(v15 + 48) = &Scaleform::GFx::AS3::Abc::Code::`vftable;
      *(_QWORD *)(v15 + 56) = Scaleform::GFx::AS3::Abc::StringView::Empty;
      v29 = (_QWORD *)(v15 + 64);
      v28 = v15 + 64;
      v30 = v15 + 64;
      *v29 = 0i64;
      v29[1] = 0i64;
      v29[2] = 0i64;
    }
    else
    {
      v16 = 0i64;
    }
    v17 = v4->Size;
    v18 = v17 + 1;
    if ( v17 + 1 >= v17 )
    {
      if ( v18 <= v4->Policy.Capacity )
        goto LABEL_16;
      v19 = v18 + (v18 >> 2);
    }
    else
    {
      if ( v18 >= v4->Policy.Capacity >> 1 )
        goto LABEL_16;
      v19 = v17 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      v4,
      v4,
      v19);
LABEL_16:
    v4->Size = v18;
    v4->Data[v18 - 1] = v16;
    v20 = v4->Data[v4->Size - 1];
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            v7,
            v6,
            (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)v4->Data[v4->Size - 1]) )
      break;
    v5->Info.Data.Data[*(signed int *)(v20 + 24)]->MethodBodyInfoInd = v14++;
    if ( v14 >= v10 )
      return 1;
  }
  v21 = v4->Data[v4->Size - 1];
  v31 = v21;
  if ( v21 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)(v21 + 64));
    *(_QWORD *)(v21 + 48) = &Scaleform::GFx::AS3::Abc::Code::`vftable;
    v31 = v21;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, *(void **)v21);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, (void *)v21);
  }
  v22 = v4->Size;
  v23 = v22 - 1;
  if ( v22 - 1 >= v22 )
  {
    if ( v23 > v4->Policy.Capacity )
    {
      v24 = v23 + (v23 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        v4,
        v4,
        v24);
    }
  }
  else if ( v23 < v4->Policy.Capacity >> 1 )
  {
    v24 = v22 - 1;
    goto LABEL_26;
  }
  v4->Size = v23;
  return 0;
}

