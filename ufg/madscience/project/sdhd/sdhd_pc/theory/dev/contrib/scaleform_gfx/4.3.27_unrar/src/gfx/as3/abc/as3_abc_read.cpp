// File Line: 23
// RVA: 0x80D090
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::File *obj)
{
  const char *CP; // rax
  __int16 v5; // r9
  __int16 v6; // r8
  const char *v7; // rax
  __int16 v8; // dx
  __int16 v9; // cx
  unsigned __int16 v10; // dx

  Scaleform::GFx::AS3::Abc::File::Clear(obj);
  CP = this->CP;
  v5 = *((unsigned __int8 *)CP + 1);
  v6 = *(unsigned __int8 *)CP;
  this->CP = CP + 2;
  obj->MinorVersion = v6 | (v5 << 8);
  v7 = this->CP;
  v8 = *((unsigned __int8 *)v7 + 1);
  v9 = *(unsigned __int8 *)v7;
  this->CP = v7 + 2;
  v10 = v9 | (v8 << 8);
  obj->MajorVersion = v10;
  return v10 == 46
      && obj->MinorVersion == 16
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Const_Pool)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Methods)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Const_Pool, &obj->Metadata)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Traits, &obj->AS3_Classes)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Traits, &obj->Scripts)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->Traits, &obj->Methods, &obj->MethodBodies);
}

// File Line: 48
// RVA: 0x80E850
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::StringDataPtr *obj,
        Scaleform::StringDataPtr *zero_val)
{
  const char *v4; // rax
  unsigned int v5; // r11d
  char v7; // r10
  __int64 v10; // rbx
  unsigned int v11; // ecx
  char v12; // dl
  int v13; // eax
  unsigned __int64 Size; // rax
  const char *Data; // r8
  char *v16; // r8
  char v17; // al
  int v18; // r9d
  char v19; // dl
  char v20; // cl

  v4 = this->CP;
  v5 = 7;
  v7 = *v4;
  this->CP = v4 + 1;
  v10 = v7 & 0x7F;
  v11 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v11 >= 0x20 )
        break;
      v12 = *this->CP++;
      v13 = (v12 & 0x7F) << v11;
      v11 += 7;
      v10 = v13 | (unsigned int)v10;
    }
    while ( v12 < 0 );
  }
  if ( (_DWORD)v10 )
  {
    Data = cp->ConstStr.Data.Data[v10].Data;
    if ( Data )
    {
      v17 = *Data;
      v16 = (char *)(Data + 1);
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
      Size = v18;
    }
    else
    {
      v16 = &customCaption;
      Size = 0i64;
    }
    obj->pStr = v16;
  }
  else
  {
    obj->pStr = zero_val->pStr;
    Size = zero_val->Size;
  }
  obj->Size = Size;
  return 1;
}

// File Line: 64
// RVA: 0x80E730
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::NamespaceInfo *obj)
{
  const char *v3; // rax
  int v5; // ebx
  bool result; // al
  Scaleform::StringDataPtr zero_val; // [rsp+20h] [rbp-18h] BYREF

  v3 = this->CP;
  v5 = *(unsigned __int8 *)v3;
  this->CP = v3 + 1;
  zero_val.Size = 0i64;
  zero_val.pStr = &customCaption;
  result = Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->NameURI, &zero_val);
  switch ( v5 )
  {
    case 5:
      obj->Kind = NS_Private;
      break;
    case 8:
    case 22:
      obj->Kind = NS_Public;
      break;
    case 23:
      obj->Kind = NS_PackageInternal;
      break;
    case 24:
      obj->Kind = NS_Protected;
      break;
    case 25:
      obj->Kind = NS_Explicit;
      break;
    case 26:
      obj->Kind = NS_StaticProtected;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}

// File Line: 130
// RVA: 0x80E490
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::Multiname *obj)
{
  const char *v3; // rax
  int v6; // r9d
  char v8; // r10
  Scaleform::GFx::AS3::Abc::MultinameKind v9; // eax
  Scaleform::GFx::AS3::Abc::Multiname *p_NameIndex; // rdx
  const char *v12; // rax
  unsigned int v13; // r8d
  char v14; // cl
  unsigned int v15; // r9d
  int v16; // r10d
  const char *v17; // rax
  char v18; // cl
  char v19; // dl
  Scaleform::GFx::AS3::Abc::Multiname *v20; // rdx
  const char *v21; // rax
  char v22; // cl
  int v23; // r9d
  const char *v24; // rax
  char v25; // cl
  char v26; // dl

  v3 = this->CP;
  v6 = *(unsigned __int8 *)v3;
  this->CP = v3 + 1;
  v8 = 1;
  switch ( v6 )
  {
    case 7:
      v9 = MN_QName;
      break;
    case 9:
      v9 = MN_Multiname;
      break;
    case 13:
      v9 = MN_QNameA;
      break;
    case 14:
      v9 = MN_MultinameA;
      break;
    case 15:
      v9 = MN_RTQName;
      break;
    case 16:
      v9 = MN_RTQNameA;
      break;
    case 17:
      v9 = MN_RTQNameL;
      break;
    case 18:
      v9 = MN_RTQNameLA;
      break;
    case 27:
      v9 = MN_MultinameL;
      break;
    case 28:
      v9 = MN_MultinameLA;
      break;
    case 29:
      v9 = MN_Typename;
      break;
    default:
      v9 = MN_Invalid;
      v8 = 0;
      break;
  }
  obj->Kind = v9;
  switch ( v9 )
  {
    case MN_QName:
    case MN_QNameA:
      if ( !v8 || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)obj) )
        goto LABEL_20;
      p_NameIndex = (Scaleform::GFx::AS3::Abc::Multiname *)&obj->NameIndex;
      break;
    case MN_RTQName:
    case MN_RTQNameA:
      if ( !v8 )
        goto LABEL_20;
      p_NameIndex = (Scaleform::GFx::AS3::Abc::Multiname *)&obj->NameIndex;
      break;
    case MN_Multiname:
    case MN_MultinameA:
      if ( !v8 || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->NameIndex) )
        goto LABEL_20;
      p_NameIndex = obj;
      break;
    case MN_MultinameL:
    case MN_MultinameLA:
      if ( !v8 )
        goto LABEL_20;
      p_NameIndex = obj;
      break;
    case MN_Typename:
      if ( !v8 )
        goto LABEL_20;
      v12 = this->CP;
      v13 = 7;
      v14 = *v12;
      v15 = 7;
      this->CP = v12 + 1;
      v16 = v14 & 0x7F;
      if ( v14 < 0 )
      {
        do
        {
          if ( v15 >= 0x20 )
            break;
          v17 = this->CP;
          v18 = v15;
          v15 += 7;
          v19 = *v17;
          this->CP = v17 + 1;
          v16 |= (v19 & 0x7F) << v18;
        }
        while ( v19 < 0 );
      }
      v20 = &cp->const_multiname.Data.Data[v16];
      obj->Ind = v20->Ind;
      obj->NextIndex = v20->NextIndex;
      obj->NameIndex = v20->NameIndex;
      obj->Kind = v20->Kind;
      v21 = this->CP;
      v22 = *v21;
      this->CP = v21 + 1;
      v23 = v22 & 0x7F;
      if ( v22 < 0 )
      {
        do
        {
          if ( v13 >= 0x20 )
            break;
          v24 = this->CP;
          v25 = v13;
          v13 += 7;
          v26 = *v24;
          this->CP = v24 + 1;
          v23 |= (v26 & 0x7F) << v25;
        }
        while ( v26 < 0 );
      }
      if ( v23 != 1 )
        goto LABEL_20;
      p_NameIndex = (Scaleform::GFx::AS3::Abc::Multiname *)&obj->NextIndex;
      break;
    default:
      if ( !v8 )
        goto LABEL_38;
      return v8;
  }
  if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)p_NameIndex) )
    return 1;
LABEL_20:
  v8 = 0;
LABEL_38:
  obj->Kind = MN_Invalid;
  return v8;
}

// File Line: 227
// RVA: 0x80C230
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *obj)
{
  const char *v4; // rax
  char v5; // r8
  unsigned int v6; // esi
  unsigned int v7; // ecx
  const char *v8; // rax
  char v9; // dl
  unsigned __int64 Size; // rax
  unsigned __int64 v11; // r14
  unsigned __int64 v12; // r8
  const char *i; // r15
  const char *v14; // rax
  char v15; // cl
  int v16; // r14d
  unsigned int v17; // r8d
  const char *v18; // rax
  char v19; // dl
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rsi
  unsigned __int64 v22; // r8
  const char *v23; // rax
  char v24; // cl
  unsigned int v25; // esi
  unsigned int v26; // r8d
  const char *v27; // rax
  char v28; // dl
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // r14
  unsigned __int64 v31; // r8
  const char *v32; // rax
  char v33; // cl
  int v34; // r14d
  unsigned int v35; // r8d
  const char *v36; // rax
  char v37; // dl
  unsigned __int64 v38; // rax
  unsigned __int64 v39; // rsi
  unsigned __int64 v40; // r8
  const char *v41; // rax
  char v42; // cl
  int v43; // r9d
  unsigned int v44; // r8d
  const char *v45; // rax
  char v46; // dl
  const char *v47; // rax
  char v48; // cl
  unsigned int v49; // ebx
  unsigned int v50; // r8d
  const char *v51; // rax
  char v52; // dl
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::StringView,339,Scaleform::ArrayDefaultPolicy> *p_ConstStr; // rsi
  unsigned __int64 v54; // rax
  unsigned __int64 v55; // r14
  unsigned __int64 v56; // r8
  Scaleform::GFx::AS3::Abc::StringView *v57; // rcx
  unsigned int v58; // r12d
  const char *v59; // rbx
  unsigned __int64 v60; // rax
  unsigned __int64 v61; // r14
  unsigned __int64 v62; // r8
  Scaleform::GFx::AS3::Abc::StringView *v63; // rcx
  const char *v64; // rax
  char v65; // cl
  int v66; // r9d
  unsigned int v67; // r8d
  const char *v68; // rax
  char v69; // dl
  const char *v70; // rax
  char v71; // cl
  unsigned int v72; // esi
  unsigned int v73; // r8d
  const char *v74; // rax
  char v75; // dl
  bool v76; // r15
  Scaleform::GFx::AS3::Abc::ConstPool *v77; // r13
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // r14
  unsigned __int64 v80; // r8
  __int64 v81; // rdx
  __int64 v82; // r14
  __int64 v83; // r12
  unsigned __int64 v84; // rax
  unsigned __int64 v85; // rsi
  Scaleform::GFx::AS3::Abc::NamespaceInfo *Data; // rdx
  unsigned __int64 v87; // rax
  unsigned __int64 v88; // rax
  __int64 v89; // r14
  unsigned __int64 v90; // r8
  Scaleform::GFx::AS3::Abc::NamespaceInfo *v91; // rax
  unsigned __int64 v92; // rax
  __int64 v93; // rdx
  const char *v94; // rax
  char v95; // cl
  unsigned int v96; // ebx
  unsigned int v97; // r15d
  __int64 v98; // r8
  const char *v99; // rax
  char v100; // dl
  char v101; // r12
  Scaleform::ArrayLH_POD<Scaleform::GFx::AS3::Abc::NamespaceSetInfo,339,Scaleform::ArrayDefaultPolicy> *p_const_ns_set; // rsi
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v103; // rdx
  unsigned __int64 v104; // rax
  unsigned __int64 v105; // r8
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v106; // rax
  unsigned __int64 v107; // rax
  unsigned __int64 v108; // r14
  unsigned __int64 v109; // r8
  __int64 v110; // r13
  char *v111; // rbx
  char v112; // cl
  unsigned int v113; // r11d
  const char *v114; // rax
  char v115; // dl
  unsigned int j; // r10d
  const char *v117; // rax
  char v118; // cl
  int v119; // r9d
  const char *v120; // rax
  char v121; // dl
  unsigned __int64 v122; // rax
  unsigned __int64 v123; // r14
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v124; // rdx
  unsigned __int64 v125; // rax
  unsigned __int64 v126; // rax
  __int64 v127; // r15
  unsigned __int64 v128; // r8
  Scaleform::GFx::AS3::Abc::NamespaceSetInfo *v129; // rax
  unsigned __int64 v130; // rax
  const char *v132; // rax
  char v133; // cl
  unsigned int v134; // r14d
  const char *v135; // rax
  char v136; // dl
  bool v137; // r15
  unsigned __int64 v138; // rsi
  void **p_Data; // rbx
  void *v140; // rdx
  unsigned __int64 v141; // rsi
  unsigned __int64 v142; // r8
  void *v143; // rax
  unsigned __int64 v144; // rax
  unsigned __int64 v145; // rsi
  void *v146; // rdx
  unsigned __int64 v147; // r12
  unsigned __int64 v148; // r12
  unsigned __int64 v149; // r8
  void *v150; // rax
  unsigned __int64 v151; // r12
  Scaleform::GFx::AS3::Abc::Multiname *v152; // rcx
  __int64 v153; // r12
  unsigned __int64 v154; // rax
  unsigned __int64 v155; // rsi
  void *v156; // rdx
  unsigned __int64 v157; // r8
  void *v158; // rax
  __int64 v159; // rdx
  __int64 v160; // [rsp+20h] [rbp-20h]
  Scaleform::GFx::AS3::Abc::NamespaceInfo obja; // [rsp+28h] [rbp-18h] BYREF
  Scaleform::GFx::AS3::Abc::ConstPool *cp; // [rsp+88h] [rbp+48h] BYREF
  __int64 v163; // [rsp+90h] [rbp+50h] BYREF
  __int64 v164; // [rsp+98h] [rbp+58h]

  cp = obj;
  v160 = -2i64;
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
      v8 = this->CP;
      v9 = *v8;
      this->CP = v8 + 1;
      v6 |= (v9 & 0x7F) << v7;
      v7 += 7;
    }
    while ( v9 < 0 );
  }
  if ( v6 > obj->ConstInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
      &obj->ConstInt,
      v6);
  Size = obj->ConstInt.Data.Size;
  v11 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v11 <= obj->ConstInt.Data.Policy.Capacity )
      goto LABEL_12;
    v12 = v11 + (v11 >> 2);
  }
  else
  {
    if ( v11 >= obj->ConstInt.Data.Policy.Capacity >> 1 )
      goto LABEL_12;
    v12 = Size + 1;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
    &obj->ConstInt,
    v12);
LABEL_12:
  obj->ConstInt.Data.Size = v11;
  i = 0i64;
  obj->ConstInt.Data.Data[v11 - 1] = 0;
  if ( v6 > 1 )
  {
    for ( i = (const char *)(v6 - 1); i; --i )
    {
      v14 = this->CP;
      v15 = *v14;
      this->CP = v14 + 1;
      v16 = v15 & 0x7F;
      v17 = 7;
      if ( v15 < 0 )
      {
        do
        {
          if ( v17 >= 0x20 )
            break;
          v18 = this->CP;
          v19 = *v18;
          this->CP = v18 + 1;
          v16 |= (v19 & 0x7F) << v17;
          v17 += 7;
        }
        while ( v19 < 0 );
      }
      v20 = obj->ConstInt.Data.Size;
      v21 = v20 + 1;
      if ( v20 + 1 >= v20 )
      {
        if ( v21 > obj->ConstInt.Data.Policy.Capacity )
        {
          v22 = v21 + (v21 >> 2);
          goto LABEL_22;
        }
      }
      else if ( v21 < obj->ConstInt.Data.Policy.Capacity >> 1 )
      {
        v22 = v20 + 1;
LABEL_22:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy> *)&obj->ConstInt,
          &obj->ConstInt,
          v22);
      }
      obj->ConstInt.Data.Size = v21;
      obj->ConstInt.Data.Data[v21 - 1] = v16;
    }
  }
  v23 = this->CP;
  v24 = *v23;
  this->CP = v23 + 1;
  v25 = v24 & 0x7F;
  v26 = 7;
  if ( v24 < 0 )
  {
    do
    {
      if ( v26 >= 0x20 )
        break;
      v27 = this->CP;
      v28 = *v27;
      this->CP = v27 + 1;
      v25 |= (v28 & 0x7F) << v26;
      v26 += 7;
    }
    while ( v28 < 0 );
  }
  if ( v25 > obj->ConstUInt.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->ConstUInt.Data,
      &obj->ConstUInt,
      v25);
  v29 = obj->ConstUInt.Data.Size;
  v30 = v29 + 1;
  if ( v29 + 1 >= v29 )
  {
    if ( v30 <= obj->ConstUInt.Data.Policy.Capacity )
      goto LABEL_35;
    v31 = v30 + (v30 >> 2);
  }
  else
  {
    if ( v30 >= obj->ConstUInt.Data.Policy.Capacity >> 1 )
      goto LABEL_35;
    v31 = v29 + 1;
  }
  Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &obj->ConstUInt.Data,
    &obj->ConstUInt,
    v31);
LABEL_35:
  obj->ConstUInt.Data.Size = v30;
  obj->ConstUInt.Data.Data[v30 - 1] = (unsigned int)i;
  if ( v25 > 1 )
  {
    for ( i = (const char *)(v25 - 1); i; --i )
    {
      v32 = this->CP;
      v33 = *v32;
      this->CP = v32 + 1;
      v34 = v33 & 0x7F;
      v35 = 7;
      if ( v33 < 0 )
      {
        do
        {
          if ( v35 >= 0x20 )
            break;
          v36 = this->CP;
          v37 = *v36;
          this->CP = v36 + 1;
          v34 |= (v37 & 0x7F) << v35;
          v35 += 7;
        }
        while ( v37 < 0 );
      }
      v38 = obj->ConstUInt.Data.Size;
      v39 = v38 + 1;
      if ( v38 + 1 >= v38 )
      {
        if ( v39 > obj->ConstUInt.Data.Policy.Capacity )
        {
          v40 = v39 + (v39 >> 2);
          goto LABEL_45;
        }
      }
      else if ( v39 < obj->ConstUInt.Data.Policy.Capacity >> 1 )
      {
        v40 = v38 + 1;
LABEL_45:
        Scaleform::ArrayDataBase<unsigned long,Scaleform::AllocatorLH_POD<unsigned long,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->ConstUInt.Data,
          &obj->ConstUInt,
          v40);
      }
      obj->ConstUInt.Data.Size = v39;
      obj->ConstUInt.Data.Data[v39 - 1] = v34;
    }
  }
  obj->DoubleCount = (unsigned int)i;
  obj->Doubles = i;
  v41 = this->CP;
  v42 = *v41;
  this->CP = v41 + 1;
  v43 = v42 & 0x7F;
  v44 = 7;
  if ( v42 < 0 )
  {
    do
    {
      if ( v44 >= 0x20 )
        break;
      v45 = this->CP;
      v46 = *v45;
      this->CP = v45 + 1;
      v43 |= (v46 & 0x7F) << v44;
      v44 += 7;
    }
    while ( v46 < 0 );
  }
  obj->DoubleCount = v43;
  obj->Doubles = this->CP;
  if ( v43 )
    this->CP += (unsigned int)(8 * v43 - 8);
  v47 = this->CP;
  v48 = *v47;
  this->CP = v47 + 1;
  v49 = v48 & 0x7F;
  v50 = 7;
  if ( v48 < 0 )
  {
    do
    {
      if ( v50 >= 0x20 )
        break;
      v51 = this->CP;
      v52 = *v51;
      this->CP = v51 + 1;
      v49 |= (v52 & 0x7F) << v50;
      v50 += 7;
    }
    while ( v52 < 0 );
  }
  p_ConstStr = &obj->ConstStr;
  if ( v49 > obj->ConstStr.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->ConstStr.Data,
      &obj->ConstStr,
      v49);
  v54 = obj->ConstStr.Data.Size;
  v55 = v54 + 1;
  if ( v54 + 1 >= v54 )
  {
    if ( v55 <= obj->ConstStr.Data.Policy.Capacity )
      goto LABEL_63;
    v56 = v55 + (v55 >> 2);
  }
  else
  {
    if ( v55 >= obj->ConstStr.Data.Policy.Capacity >> 1 )
      goto LABEL_63;
    v56 = v54 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
    &obj->ConstStr.Data,
    &obj->ConstStr,
    v56);
LABEL_63:
  obj->ConstStr.Data.Size = v55;
  v57 = &p_ConstStr->Data.Data[v55 - 1];
  if ( v57 )
    v57->Data = Scaleform::GFx::AS3::Abc::StringView::Empty;
  if ( v49 )
  {
    v58 = v49 - 1;
    while ( (unsigned int)i < v58 )
    {
      v59 = this->CP;
      v60 = p_ConstStr->Data.Size;
      v61 = v60 + 1;
      if ( v60 + 1 >= v60 )
      {
        if ( v61 <= p_ConstStr->Data.Policy.Capacity )
          goto LABEL_74;
        v62 = v61 + (v61 >> 2);
      }
      else
      {
        if ( v61 >= p_ConstStr->Data.Policy.Capacity >> 1 )
          goto LABEL_74;
        v62 = v60 + 1;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &p_ConstStr->Data,
        p_ConstStr,
        v62);
LABEL_74:
      p_ConstStr->Data.Size = v61;
      v63 = &p_ConstStr->Data.Data[v61 - 1];
      if ( v63 )
        v63->Data = v59;
      v64 = this->CP;
      v65 = *v64;
      this->CP = v64 + 1;
      v66 = v65 & 0x7F;
      v67 = 7;
      if ( v65 < 0 )
      {
        do
        {
          if ( v67 >= 0x20 )
            break;
          v68 = this->CP;
          v69 = *v68;
          this->CP = v68 + 1;
          v66 |= (v69 & 0x7F) << v67;
          v67 += 7;
        }
        while ( v69 < 0 );
      }
      this->CP += v66;
      LODWORD(i) = (_DWORD)i + 1;
    }
  }
  v70 = this->CP;
  v71 = *v70;
  this->CP = v70 + 1;
  v72 = v71 & 0x7F;
  v73 = 7;
  if ( v71 < 0 )
  {
    do
    {
      if ( v73 >= 0x20 )
        break;
      v74 = this->CP;
      v75 = *v74;
      this->CP = v74 + 1;
      v72 |= (v75 & 0x7F) << v73;
      v73 += 7;
    }
    while ( v75 < 0 );
  }
  v76 = 1;
  v77 = cp;
  if ( v72 > cp->ConstNamespace.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::NamespaceInfo,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &cp->ConstNamespace.Data,
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
      &v77->ConstNamespace.Data,
      &v77->ConstNamespace,
      v80);
  }
  v77->ConstNamespace.Data.Size = v79;
  v81 = (__int64)&v77->ConstNamespace.Data.Data[v79 - 1];
  v163 = v81;
  v164 = v81;
  v82 = 0i64;
  if ( v81 )
  {
    *(_DWORD *)v81 = 0;
    *(_QWORD *)(v81 + 8) = &customCaption;
    *(_QWORD *)(v81 + 16) = 0i64;
  }
  if ( v72 <= 1 )
    goto LABEL_117;
  v83 = v72 - 1;
  do
  {
    obja.Kind = NS_Public;
    obja.NameURI.pStr = &customCaption;
    obja.NameURI.Size = 0i64;
    v76 = v76 && Scaleform::GFx::AS3::Abc::Reader::Read(this, v77, &obja);
    v84 = v77->ConstNamespace.Data.Size;
    v85 = v84 + 1;
    if ( v84 + 1 >= v84 )
    {
      if ( v85 <= v77->ConstNamespace.Data.Policy.Capacity )
        goto LABEL_113;
      Data = v77->ConstNamespace.Data.Data;
      v92 = v85 + (v85 >> 2);
      if ( v92 )
      {
        v87 = v92 + 3;
        goto LABEL_103;
      }
    }
    else
    {
      if ( v85 >= v77->ConstNamespace.Data.Policy.Capacity >> 1 )
        goto LABEL_113;
      Data = v77->ConstNamespace.Data.Data;
      if ( v84 != -1i64 )
      {
        v87 = v84 + 4;
LABEL_103:
        v88 = v87 >> 2;
        v89 = 4 * v88;
        v90 = 96 * v88;
        if ( Data )
        {
          v91 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             Data,
                                                             v90);
        }
        else
        {
          LODWORD(v163) = 339;
          v91 = (Scaleform::GFx::AS3::Abc::NamespaceInfo *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::NamespaceInfo,339,Scaleform::ArrayDefaultPolicy> *, unsigned __int64, __int64 *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                             Scaleform::Memory::pGlobalHeap,
                                                             &v77->ConstNamespace,
                                                             v90,
                                                             &v163,
                                                             v160);
        }
        v77->ConstNamespace.Data.Data = v91;
        v77->ConstNamespace.Data.Policy.Capacity = v89;
        v82 = 0i64;
        goto LABEL_113;
      }
    }
    if ( Data )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
      v77->ConstNamespace.Data.Data = 0i64;
    }
    v77->ConstNamespace.Data.Policy.Capacity = 0i64;
LABEL_113:
    v77->ConstNamespace.Data.Size = v85;
    v93 = (__int64)&v77->ConstNamespace.Data.Data[v85 - 1];
    v163 = v93;
    v164 = v93;
    if ( v93 )
    {
      *(_DWORD *)v93 = obja.Kind;
      *(Scaleform::StringDataPtr *)(v93 + 8) = obja.NameURI;
    }
    --v83;
  }
  while ( v83 );
  if ( !v76 )
    return 0;
LABEL_117:
  v94 = this->CP;
  v95 = *v94;
  this->CP = v94 + 1;
  v96 = v95 & 0x7F;
  v97 = 7;
  v98 = 7i64;
  if ( v95 < 0 )
  {
    do
    {
      if ( (unsigned int)v98 >= 0x20 )
        break;
      v99 = this->CP;
      v100 = *v99;
      this->CP = v99 + 1;
      v96 |= (v100 & 0x7F) << v98;
      v98 = (unsigned int)(v98 + 7);
    }
    while ( v100 < 0 );
  }
  v101 = 1;
  p_const_ns_set = &v77->const_ns_set;
  if ( v96 > v77->const_ns_set.Data.Policy.Capacity )
  {
    v103 = p_const_ns_set->Data.Data;
    if ( v96 )
    {
      v104 = ((unsigned __int64)v96 + 3) >> 2;
      v82 = 4 * v104;
      v105 = 32 * v104;
      if ( v103 )
      {
        v106 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               v103,
                                                               v105);
      }
      else
      {
        LODWORD(v163) = 339;
        v106 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                               Scaleform::Memory::pGlobalHeap,
                                                               &v77->const_ns_set,
                                                               v105,
                                                               &v163);
      }
      p_const_ns_set->Data.Data = v106;
    }
    else if ( v103 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::NamespaceSetInfo *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v103,
        v98);
      p_const_ns_set->Data.Data = 0i64;
    }
    v77->const_ns_set.Data.Policy.Capacity = v82;
  }
  v107 = v77->const_ns_set.Data.Size;
  v108 = v107 + 1;
  if ( v107 + 1 >= v107 )
  {
    if ( v108 > v77->const_ns_set.Data.Policy.Capacity )
    {
      v109 = v108 + (v108 >> 2);
LABEL_134:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::StringView,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::StringView,339>,Scaleform::ArrayDefaultPolicy> *)&v77->const_ns_set,
        &v77->const_ns_set,
        v109);
    }
  }
  else if ( v108 < v77->const_ns_set.Data.Policy.Capacity >> 1 )
  {
    v109 = v107 + 1;
    goto LABEL_134;
  }
  v77->const_ns_set.Data.Size = v108;
  p_const_ns_set->Data.Data[v108 - 1].Data = (const char *)cp;
  p_const_ns_set->Data.Data[v77->const_ns_set.Data.Size - 1].Data = 0i64;
  if ( v96 <= 1 )
    goto LABEL_168;
  v110 = v96 - 1;
  v111 = (char *)cp;
  while ( 2 )
  {
    if ( v101 )
    {
      v111 = (char *)this->CP;
      v112 = *v111;
      this->CP = v111 + 1;
      v113 = v112 & 0x7F;
      v98 = 7i64;
      if ( v112 < 0 )
      {
        do
        {
          if ( (unsigned int)v98 >= 0x20 )
            break;
          v114 = this->CP;
          v115 = *v114;
          this->CP = v114 + 1;
          v113 |= (v115 & 0x7F) << v98;
          v98 = (unsigned int)(v98 + 7);
        }
        while ( v115 < 0 );
      }
      for ( j = 0; j < v113; ++j )
      {
        v117 = this->CP;
        v118 = *v117;
        this->CP = v117 + 1;
        v119 = v118 & 0x7F;
        v98 = 7i64;
        if ( v118 < 0 )
        {
          do
          {
            if ( (unsigned int)v98 >= 0x20 )
              break;
            v120 = this->CP;
            v121 = *v120;
            this->CP = v120 + 1;
            v119 |= (v121 & 0x7F) << v98;
            v98 = (unsigned int)(v98 + 7);
          }
          while ( v121 < 0 );
        }
        if ( !v119 )
          goto LABEL_149;
      }
      v101 = 1;
    }
    else
    {
LABEL_149:
      v101 = 0;
    }
    v122 = p_const_ns_set->Data.Size;
    v123 = v122 + 1;
    if ( v122 + 1 >= v122 )
    {
      if ( v123 > p_const_ns_set->Data.Policy.Capacity )
      {
        v124 = p_const_ns_set->Data.Data;
        v130 = v123 + (v123 >> 2);
        if ( !v130 )
          goto LABEL_158;
        v125 = v130 + 3;
LABEL_154:
        v126 = v125 >> 2;
        v127 = 4 * v126;
        v128 = 32 * v126;
        if ( v124 )
        {
          v129 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->vfptr->Realloc(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 v124,
                                                                 v128);
        }
        else
        {
          LODWORD(v163) = 339;
          v129 = (Scaleform::GFx::AS3::Abc::NamespaceSetInfo *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                                 Scaleform::Memory::pGlobalHeap,
                                                                 p_const_ns_set,
                                                                 v128,
                                                                 &v163);
        }
        p_const_ns_set->Data.Data = v129;
        p_const_ns_set->Data.Policy.Capacity = v127;
        v97 = 7;
      }
    }
    else if ( v123 < p_const_ns_set->Data.Policy.Capacity >> 1 )
    {
      v124 = p_const_ns_set->Data.Data;
      if ( v122 != -1i64 )
      {
        v125 = v122 + 4;
        goto LABEL_154;
      }
LABEL_158:
      if ( v124 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::NamespaceSetInfo *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v124,
          v98);
        p_const_ns_set->Data.Data = 0i64;
      }
      p_const_ns_set->Data.Policy.Capacity = 0i64;
    }
    p_const_ns_set->Data.Size = v123;
    p_const_ns_set->Data.Data[v123 - 1].Data = v111;
    if ( --v110 )
      continue;
    break;
  }
  if ( !v101 )
    return 0;
  v77 = cp;
LABEL_168:
  v132 = this->CP;
  v133 = *v132;
  this->CP = v132 + 1;
  v134 = v133 & 0x7F;
  if ( v133 < 0 )
  {
    do
    {
      if ( v97 >= 0x20 )
        break;
      v135 = this->CP;
      v136 = *v135;
      this->CP = v135 + 1;
      v134 |= (v136 & 0x7F) << v97;
      v97 += 7;
    }
    while ( v136 < 0 );
  }
  v137 = 1;
  v138 = v134 + 1;
  p_Data = (void **)&v77->const_multiname.Data.Data;
  if ( v138 > v77->const_multiname.Data.Policy.Capacity )
  {
    v140 = *p_Data;
    if ( v134 == -1 )
    {
      if ( v140 )
      {
        ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
          Scaleform::Memory::pGlobalHeap,
          v140,
          v98);
        *p_Data = 0i64;
      }
      v77->const_multiname.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v141 = (v138 + 3) & 0xFFFFFFFFFFFFFFFCui64;
      v142 = 16 * v141;
      if ( v140 )
      {
        v143 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v140, v142);
      }
      else
      {
        LODWORD(cp) = 339;
        v143 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 &v77->const_multiname,
                 v142,
                 &cp);
      }
      *p_Data = v143;
      v77->const_multiname.Data.Policy.Capacity = v141;
    }
  }
  v144 = v77->const_multiname.Data.Size;
  v145 = v144 + 1;
  if ( v144 + 1 >= v144 )
  {
    if ( v145 > v77->const_multiname.Data.Policy.Capacity )
    {
      v146 = *p_Data;
      v151 = v145 + (v145 >> 2);
      if ( !v151 )
        goto LABEL_188;
      v147 = v151 + 3;
LABEL_184:
      v148 = v147 & 0xFFFFFFFFFFFFFFFCui64;
      v149 = 16 * v148;
      if ( v146 )
      {
        v150 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v146, v149);
      }
      else
      {
        LODWORD(cp) = 339;
        v150 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                 Scaleform::Memory::pGlobalHeap,
                 &v77->const_multiname,
                 v149,
                 &cp);
      }
      *p_Data = v150;
      v77->const_multiname.Data.Policy.Capacity = v148;
    }
  }
  else if ( v145 < v77->const_multiname.Data.Policy.Capacity >> 1 )
  {
    v146 = *p_Data;
    if ( v144 != -1i64 )
    {
      v147 = v144 + 4;
      goto LABEL_184;
    }
LABEL_188:
    if ( v146 )
    {
      ((void (__fastcall *)(Scaleform::MemoryHeap *, void *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Free)(
        Scaleform::Memory::pGlobalHeap,
        v146,
        v98);
      *p_Data = 0i64;
    }
    v77->const_multiname.Data.Policy.Capacity = 0i64;
  }
  v77->const_multiname.Data.Size = v145;
  v152 = (Scaleform::GFx::AS3::Abc::Multiname *)((char *)*p_Data + 16 * v145 - 16);
  if ( v152 )
    *v152 = Scaleform::GFx::AS3::Abc::Multiname::AnyType;
  if ( v134 > 1 )
  {
    v153 = v134 - 1;
    do
    {
      *(_QWORD *)&obja.Kind = -1i64;
      obja.NameURI.pStr = 0i64;
      v137 = v137 && Scaleform::GFx::AS3::Abc::Reader::Read(this, v77, (Scaleform::GFx::AS3::Abc::Multiname *)&obja);
      v154 = v77->const_multiname.Data.Size;
      v155 = v154 + 1;
      if ( v154 + 1 >= v154 )
      {
        if ( v155 > v77->const_multiname.Data.Policy.Capacity )
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::Multiname,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::Multiname,339>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &v77->const_multiname.Data,
            &v77->const_multiname,
            v155 + (v155 >> 2));
      }
      else if ( v155 < v77->const_multiname.Data.Policy.Capacity >> 1 )
      {
        v156 = *p_Data;
        if ( v154 == -1i64 )
        {
          if ( v156 )
          {
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
            *p_Data = 0i64;
          }
          v77->const_multiname.Data.Policy.Capacity = 0i64;
        }
        else
        {
          v157 = 16 * ((v154 + 4) & 0xFFFFFFFFFFFFFFFCui64);
          if ( v156 )
          {
            v158 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v156, v157);
          }
          else
          {
            LODWORD(cp) = 339;
            v158 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     &v77->const_multiname,
                     v157,
                     &cp);
          }
          *p_Data = v158;
          v77->const_multiname.Data.Policy.Capacity = (v155 + 3) & 0xFFFFFFFFFFFFFFFCui64;
        }
      }
      v77->const_multiname.Data.Size = v155;
      v159 = (__int64)*p_Data + 16 * v155 - 16;
      if ( v159 )
      {
        *(_DWORD *)v159 = obja.Kind;
        *(_DWORD *)(v159 + 4) = *((_DWORD *)&obja.Kind + 1);
        *(_QWORD *)(v159 + 8) = obja.NameURI.pStr;
      }
      --v153;
    }
    while ( v153 );
  }
  return v137;
}54 + 4) & 0xFFFFFFFFFFFFFFFCui64);
          if ( v156 )
          {
            v158 = Scaleform::Memory::pGlobalHeap->vfptr->Realloc(Scaleform::Memory::pGlobalHeap, v156, v157);
          }
          else
          {
            LODWORD(cp) = 339;
            v158 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     &v77->const_multiname,
                     v157,
                     &cp)

// File Line: 355
// RVA: 0x80BD50
char __fastcall Scaleform::GFx::AS3::Abc::Read(const char **ptr, Scaleform::GFx::AS3::Abc::MethodInfo *obj)
{
  char v4; // r8
  unsigned int v5; // ecx
  int v6; // r15d
  char v7; // dl
  int v8; // eax
  unsigned int v9; // r8d
  char v10; // cl
  int v11; // r9d
  char v12; // cl
  char v13; // dl
  __int64 i; // r14
  unsigned int v16; // r8d
  char v17; // cl
  int v18; // ebp
  char v19; // cl
  char v20; // dl
  unsigned __int64 Size; // rax
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // r8
  unsigned int *Data; // rax
  unsigned int v25; // edx
  char v26; // cl
  char v27; // cl
  char v28; // cl
  unsigned int v29; // r8d
  char v30; // cl
  int v31; // r14d
  char v32; // cl
  char v33; // dl
  int j; // ebp
  unsigned int v35; // r8d
  char v36; // cl
  int v37; // r9d
  char v38; // cl
  char v39; // dl
  char v40; // cl
  unsigned __int64 v41; // rax
  unsigned __int64 v42; // rdi
  unsigned __int64 v43; // r8
  Scaleform::GFx::AS3::Abc::ValueDetail *v44; // rax
  Scaleform::GFx::AS3::Abc::ValueDetail *v45; // rcx
  __int64 k; // r14
  unsigned int v47; // r8d
  char v48; // cl
  int v49; // ebp
  char v50; // cl
  char v51; // dl
  unsigned __int64 v52; // rax
  unsigned __int64 v53; // rdi
  unsigned __int64 v54; // r8
  int *v55; // rax
  Scaleform::GFx::AS3::Abc::ValueDetail v56; // [rsp+60h] [rbp+18h]

  v4 = *(*ptr)++;
  v5 = 7;
  v6 = v4 & 0x7F;
  if ( v4 < 0 )
  {
    do
    {
      if ( v5 >= 0x20 )
        break;
      v7 = *(*ptr)++;
      v8 = (v7 & 0x7F) << v5;
      v5 += 7;
      v6 |= v8;
    }
    while ( v7 < 0 );
  }
  v9 = 7;
  v10 = *(*ptr)++;
  v11 = v10 & 0x7F;
  if ( v10 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v12 = v9;
      v9 += 7;
      v13 = *(*ptr)++;
      v11 |= (v13 & 0x7F) << v12;
    }
    while ( v13 < 0 );
  }
  obj->RetTypeInd = v11;
  if ( v11 < 0 )
    return 0;
  if ( v6 > obj->ParamTypes.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&obj->ParamTypes,
      &obj->ParamTypes,
      v6);
  if ( v6 > 0 )
  {
    for ( i = (unsigned int)v6; i; --i )
    {
      v16 = 7;
      v17 = *(*ptr)++;
      v18 = v17 & 0x7F;
      if ( v17 < 0 )
      {
        do
        {
          if ( v16 >= 0x20 )
            break;
          v19 = v16;
          v16 += 7;
          v20 = *(*ptr)++;
          v18 |= (v20 & 0x7F) << v19;
        }
        while ( v20 < 0 );
      }
      Size = obj->ParamTypes.Data.Size;
      v22 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v22 > obj->ParamTypes.Data.Policy.Capacity )
        {
          v23 = v22 + (v22 >> 2);
          goto LABEL_21;
        }
      }
      else if ( v22 < obj->ParamTypes.Data.Policy.Capacity >> 1 )
      {
        v23 = Size + 1;
LABEL_21:
        Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          (Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy> *)&obj->ParamTypes,
          &obj->ParamTypes,
          v23);
      }
      Data = obj->ParamTypes.Data.Data;
      obj->ParamTypes.Data.Size = v22;
      Data[v22 - 1] = v18;
    }
  }
  v25 = 7;
  v26 = *(*ptr)++;
  if ( v26 < 0 )
  {
    do
    {
      if ( v25 >= 0x20 )
        break;
      v25 += 7;
      v27 = *(*ptr)++;
    }
    while ( v27 < 0 );
  }
  v28 = *(*ptr)++;
  obj->Flags = v28;
  if ( (v28 & 8) != 0 )
  {
    v29 = 7;
    v30 = *(*ptr)++;
    v31 = v30 & 0x7F;
    if ( v30 < 0 )
    {
      do
      {
        if ( v29 >= 0x20 )
          break;
        v32 = v29;
        v29 += 7;
        v33 = *(*ptr)++;
        v31 |= (v33 & 0x7F) << v32;
      }
      while ( v33 < 0 );
    }
    if ( v31 > obj->OptionalParams.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&obj->OptionalParams,
        &obj->OptionalParams,
        v31);
    for ( j = 0; j < v31; ++j )
    {
      v35 = 7;
      v36 = *(*ptr)++;
      v37 = v36 & 0x7F;
      if ( v36 < 0 )
      {
        do
        {
          if ( v35 >= 0x20 )
            break;
          v38 = v35;
          v35 += 7;
          v39 = *(*ptr)++;
          v37 |= (v39 & 0x7F) << v38;
        }
        while ( v39 < 0 );
      }
      v56.ValueIndex = v37;
      v40 = *(*ptr)++;
      v56.Kind = v40;
      if ( v37 < 0 )
        return 0;
      v41 = obj->OptionalParams.Data.Size;
      v42 = v41 + 1;
      if ( v41 + 1 >= v41 )
      {
        if ( v42 <= obj->OptionalParams.Data.Policy.Capacity )
          goto LABEL_44;
        v43 = v42 + (v42 >> 2);
      }
      else
      {
        if ( v42 >= obj->OptionalParams.Data.Policy.Capacity >> 1 )
          goto LABEL_44;
        v43 = v41 + 1;
      }
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&obj->OptionalParams,
        &obj->OptionalParams,
        v43);
LABEL_44:
      v44 = obj->OptionalParams.Data.Data;
      obj->OptionalParams.Data.Size = v42;
      v45 = &v44[v42 - 1];
      if ( v45 )
        *v45 = v56;
    }
  }
  if ( obj->Flags < 0 )
  {
    if ( v6 > obj->ParamNames.Data.Policy.Capacity )
      Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &obj->ParamNames.Data,
        &obj->ParamNames,
        v6);
    if ( v6 > 0 )
    {
      for ( k = (unsigned int)v6; k; --k )
      {
        v47 = 7;
        v48 = *(*ptr)++;
        v49 = v48 & 0x7F;
        if ( v48 < 0 )
        {
          do
          {
            if ( v47 >= 0x20 )
              break;
            v50 = v47;
            v47 += 7;
            v51 = *(*ptr)++;
            v49 |= (v51 & 0x7F) << v50;
          }
          while ( v51 < 0 );
        }
        v52 = obj->ParamNames.Data.Size;
        v53 = v52 + 1;
        if ( v52 + 1 >= v52 )
        {
          if ( v53 > obj->ParamNames.Data.Policy.Capacity )
          {
            v54 = v53 + (v53 >> 2);
            goto LABEL_61;
          }
        }
        else if ( v53 < obj->ParamNames.Data.Policy.Capacity >> 1 )
        {
          v54 = v52 + 1;
LABEL_61:
          Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            &obj->ParamNames.Data,
            &obj->ParamNames,
            v54);
        }
        v55 = obj->ParamNames.Data.Data;
        obj->ParamNames.Data.Size = v53;
        v55[v53 - 1] = v49;
      }
    }
  }
  return 1;
}

// File Line: 426
// RVA: 0x80D2F0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  const char *CP; // rax
  char v5; // dl
  int v6; // r14d
  unsigned int v7; // ecx
  const char *v8; // rax
  char v9; // dl
  int i; // ebp
  __int64 v11; // rax
  Scaleform::GFx::AS3::Abc::MethodInfo *v12; // rsi
  _QWORD *v13; // rax
  unsigned __int64 Size; // rax
  unsigned __int64 v15; // rdi
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rcx
  Scaleform::GFx::AS3::Abc::MethodInfo *v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  __int64 v23; // [rsp+20h] [rbp-58h]
  Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *v24; // [rsp+28h] [rbp-50h]
  int v25; // [rsp+88h] [rbp+10h] BYREF
  __int64 v26; // [rsp+90h] [rbp+18h]
  Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *p_ParamNames; // [rsp+98h] [rbp+20h]

  v23 = -2i64;
  CP = this->CP;
  v5 = *CP;
  this->CP = CP + 1;
  v6 = v5 & 0x7F;
  v7 = 7;
  if ( v5 < 0 )
  {
    do
    {
      if ( v7 >= 0x20 )
        break;
      v8 = this->CP;
      v9 = *v8;
      this->CP = v8 + 1;
      v6 |= (v9 & 0x7F) << v7;
      v7 += 7;
    }
    while ( v9 < 0 );
  }
  if ( v6 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v6);
  for ( i = 0; i < v6; ++i )
  {
    v25 = 338;
    v11 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, int *, __int64, Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            this,
            88i64,
            &v25,
            v23,
            v24);
    v12 = (Scaleform::GFx::AS3::Abc::MethodInfo *)v11;
    v26 = v11;
    if ( v11 )
    {
      *(_QWORD *)(v11 + 4) = -1i64;
      v13 = (_QWORD *)(v11 + 16);
      *v13 = 0i64;
      v13[1] = 0i64;
      v13[2] = 0i64;
      v12->OptionalParams.Data.Data = 0i64;
      v12->OptionalParams.Data.Size = 0i64;
      v12->OptionalParams.Data.Policy.Capacity = 0i64;
      p_ParamNames = &v12->ParamNames;
      v24 = &v12->ParamNames;
      v12->ParamNames.Data.Data = 0i64;
      v12->ParamNames.Data.Size = 0i64;
      v12->ParamNames.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v12 = 0i64;
    }
    Size = obj->Size;
    v15 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v15 <= obj->Policy.Capacity )
        goto LABEL_17;
      v16 = v15 + (v15 >> 2);
    }
    else
    {
      if ( v15 >= obj->Policy.Capacity >> 1 )
        goto LABEL_17;
      v16 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v16);
LABEL_17:
    obj->Size = v15;
    obj->Data[v15 - 1] = (unsigned __int64)v12;
    if ( !Scaleform::GFx::AS3::Abc::Read(&this->CP, (Scaleform::GFx::AS3::Abc::MethodInfo *)obj->Data[obj->Size - 1]) )
    {
      v17 = obj->Size;
      v18 = (Scaleform::GFx::AS3::Abc::MethodInfo *)obj->Data[v17 - 1];
      if ( v18 )
      {
        Scaleform::GFx::AS3::Abc::MethodInfo::~MethodInfo((Scaleform::GFx::AS3::Abc::MethodInfo *)obj->Data[v17 - 1]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
      }
      v19 = obj->Size;
      v20 = v19 - 1;
      if ( v19 - 1 >= v19 )
      {
        if ( v20 > obj->Policy.Capacity )
        {
          v21 = v20 + (v20 >> 2);
LABEL_26:
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            obj,
            obj,
            v21);
        }
      }
      else if ( v20 < obj->Policy.Capacity >> 1 )
      {
        v21 = v19 - 1;
        goto LABEL_26;
      }
      obj->Size = v20;
      return 0;
    }
  }
  return 1;
}

// File Line: 451
// RVA: 0x80E0E0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::GFx::AS3::Abc::MetadataInfo *obj)
{
  __int64 v3; // rbp
  const char *v6; // rax
  char v7; // cl
  unsigned int v8; // r8d
  __int64 v9; // rsi
  const char *v10; // rax
  char v11; // cl
  char v12; // dl
  Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *p_Items; // r14
  __int64 v14; // r15
  Scaleform::GFx::AS3::Abc::MetadataInfo::Item *v15; // r9
  char v16; // dl
  unsigned int v17; // ecx
  int v18; // r8d
  char v19; // dl
  int v20; // eax
  __int64 v21; // r9
  const char *v22; // rax
  unsigned int v23; // ecx
  char v24; // dl
  int v25; // r8d
  char v26; // dl
  int v27; // eax
  Scaleform::StringDataPtr zero_val; // [rsp+20h] [rbp-28h] BYREF

  v3 = 0i64;
  zero_val.pStr = 0i64;
  zero_val.Size = 0i64;
  if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, cp, &obj->Name, &zero_val) )
    return 0;
  v6 = this->CP;
  v7 = *v6;
  this->CP = v6 + 1;
  v8 = 7;
  v9 = v7 & 0x7F;
  if ( v7 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = this->CP;
      v11 = v8;
      v8 += 7;
      v12 = *v10;
      this->CP = v10 + 1;
      v9 = ((v12 & 0x7F) << v11) | (unsigned int)v9;
    }
    while ( v12 < 0 );
  }
  p_Items = (Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *)&obj->Items;
  v14 = (int)v9;
  if ( (int)v9 > p_Items->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      p_Items,
      p_Items,
      (int)v9);
  if ( (int)v9 > 0 )
  {
    do
    {
      v15 = Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>>::PushDefault((Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy> > *)p_Items);
      v16 = *this->CP++;
      v17 = 7;
      v18 = v16 & 0x7F;
      if ( v16 < 0 )
      {
        do
        {
          if ( v17 >= 0x20 )
            break;
          v19 = *this->CP++;
          v20 = (v19 & 0x7F) << v17;
          v17 += 7;
          v18 |= v20;
        }
        while ( v19 < 0 );
      }
      v15->KeyInd = v18;
      --v9;
    }
    while ( v9 );
  }
  if ( v14 > 0 )
  {
    do
    {
      v21 = (__int64)&p_Items->Data[v3];
      v22 = this->CP;
      v23 = 7;
      v24 = *v22;
      this->CP = v22 + 1;
      v25 = v24 & 0x7F;
      if ( v24 < 0 )
      {
        do
        {
          if ( v23 >= 0x20 )
            break;
          v26 = *this->CP++;
          v27 = (v26 & 0x7F) << v23;
          v23 += 7;
          v25 |= v27;
        }
        while ( v26 < 0 );
      }
      *(_DWORD *)(v21 + 4) = v25;
      ++v3;
    }
    while ( v3 < v14 );
  }
  return 1;
}

// File Line: 497
// RVA: 0x80E280
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::ConstPool *cp,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  const char *v6; // rax
  char v7; // r8
  int v8; // ebp
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  int v12; // r14d
  Scaleform::GFx::AS3::Abc::MetadataInfo *v13; // rax
  Scaleform::GFx::AS3::Abc::MetadataInfo *v14; // rsi
  unsigned __int64 Size; // rax
  unsigned __int64 v16; // rdi
  unsigned __int64 v17; // r8
  Scaleform::GFx::AS3::Abc::MetadataInfo *v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  __int64 v23; // [rsp+20h] [rbp-58h]
  Scaleform::GFx::AS3::Abc::MetadataInfo *v24; // [rsp+28h] [rbp-50h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *p_Items; // [rsp+30h] [rbp-48h]
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *v26; // [rsp+38h] [rbp-40h]
  void *v27; // [rsp+98h] [rbp+20h] BYREF

  v23 = -2i64;
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
      v10 = this->CP;
      v11 = *v10;
      this->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v8);
  v12 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v27) = 338;
    v13 = (Scaleform::GFx::AS3::Abc::MetadataInfo *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, void **, __int64, Scaleform::GFx::AS3::Abc::MetadataInfo *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *, Scaleform::ArrayLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338,Scaleform::ArrayDefaultPolicy> *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      this,
                                                      40i64,
                                                      &v27,
                                                      v23,
                                                      v24,
                                                      p_Items,
                                                      v26);
    v14 = v13;
    v24 = v13;
    if ( v13 )
    {
      v13->Name.pStr = 0i64;
      v13->Name.Size = 0i64;
      p_Items = &v13->Items;
      v26 = &v13->Items;
      v13->Items.Data.Data = 0i64;
      v13->Items.Data.Size = 0i64;
      v13->Items.Data.Policy.Capacity = 0i64;
    }
    else
    {
      v14 = 0i64;
    }
    Size = obj->Size;
    v16 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v16 <= obj->Policy.Capacity )
        goto LABEL_16;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= obj->Policy.Capacity >> 1 )
        goto LABEL_16;
      v17 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v17);
LABEL_16:
    obj->Size = v16;
    obj->Data[v16 - 1] = (unsigned __int64)v14;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            this,
            cp,
            (Scaleform::GFx::AS3::Abc::MetadataInfo *)obj->Data[obj->Size - 1]) )
      break;
    if ( ++v12 >= v8 )
      return 1;
  }
  v18 = (Scaleform::GFx::AS3::Abc::MetadataInfo *)obj->Data[obj->Size - 1];
  v27 = v18;
  if ( v18 )
  {
    v27 = &v18->Items;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18->Items.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
  }
  v19 = obj->Size;
  v20 = v19 - 1;
  if ( v19 - 1 >= v19 )
  {
    if ( v20 > obj->Policy.Capacity )
    {
      v21 = v20 + (v20 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        v21);
    }
  }
  else if ( v20 < obj->Policy.Capacity >> 1 )
  {
    v21 = v19 - 1;
    goto LABEL_26;
  }
  obj->Size = v20;
  return 0;
}

// File Line: 525
// RVA: 0x80D500
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitInfo *obj)
{
  const char *CP; // rax
  unsigned int v3; // ebx
  char v5; // r8
  unsigned int v7; // ecx
  int v8; // r9d
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
  const char *v21; // rax
  char v22; // bl
  bool IsValidValueKind; // al
  Scaleform::GFx::AS3::Abc::ValueDetail v24; // [rsp+50h] [rbp+18h]

  CP = this->CP;
  v3 = 7;
  v5 = *CP;
  this->CP = CP + 1;
  v7 = 7;
  v8 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v7 >= 0x20 )
        break;
      v9 = *this->CP++;
      v10 = (v9 & 0x7F) << v7;
      v7 += 7;
      v8 |= v10;
    }
    while ( v9 < 0 );
  }
  obj->name_ind = v8;
  v11 = this->CP;
  v12 = *v11;
  this->CP = v11 + 1;
  v13 = obj->name_ind < 0;
  obj->kind = v12;
  if ( v13 )
    return 0;
  switch ( v12 & 0xF )
  {
    case 0:
    case 6:
      if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->SlotId)
        && Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->Ind) )
      {
        v15 = *this->CP++;
        v16 = v15 & 0x7F;
        if ( v15 < 0 )
        {
          do
          {
            if ( v3 >= 0x20 )
              break;
            v17 = this->CP;
            v18 = v3;
            v3 += 7;
            v19 = *v17;
            this->CP = v17 + 1;
            v16 |= (v19 & 0x7F) << v18;
          }
          while ( v19 < 0 );
        }
        v20 = 1;
        if ( !v16 )
          goto LABEL_22;
        v21 = this->CP;
        v22 = *v21;
        this->CP = v21 + 1;
        IsValidValueKind = Scaleform::GFx::AS3::Abc::IsValidValueKind(v22);
        v20 = 1;
        v24.Kind = v22;
        v24.ValueIndex = v16;
        if ( !IsValidValueKind )
          v20 = 0;
        obj->default_value = v24;
        if ( v20 )
          goto LABEL_22;
      }
      goto LABEL_16;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->SlotId)
        || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->Ind)
        || obj->SlotId < 0
        || obj->Ind < 0 )
      {
        goto LABEL_16;
      }
      v20 = 1;
LABEL_22:
      if ( (obj->kind & 0x40) != 0 )
        v20 = Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->meta_info) != 0;
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
char __fastcall Scaleform::GFx::AS3::Abc::Reader::ReadTraits(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *t,
        Scaleform::ArrayLH_POD<long,338,Scaleform::ArrayDefaultPolicy> *obj_traits)
{
  const char *CP; // rax
  char v7; // r9
  int v8; // r14d
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  unsigned __int64 v12; // r8
  int v13; // r12d
  unsigned __int64 Size; // rbp
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  __int64 v18; // rax
  Scaleform::GFx::AS3::Abc::TraitInfo *v19; // rbp
  _QWORD *v20; // rax
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rsi
  unsigned __int64 v23; // r8
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rsi
  unsigned __int64 v26; // r8
  Scaleform::GFx::AS3::Abc::TraitInfo *v27; // rdi
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rdi
  unsigned __int64 v30; // r8
  __int64 v32; // [rsp+20h] [rbp-68h]
  _QWORD *v33; // [rsp+28h] [rbp-60h]
  _QWORD *v34; // [rsp+30h] [rbp-58h]
  void *p_meta_info; // [rsp+98h] [rbp+10h] BYREF
  __int64 v36; // [rsp+A0h] [rbp+18h]
  _QWORD *v37; // [rsp+A8h] [rbp+20h]

  v32 = -2i64;
  CP = this->CP;
  v7 = *CP;
  this->CP = CP + 1;
  v8 = v7 & 0x7F;
  v9 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v10 = this->CP;
      v11 = *v10;
      this->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > obj_traits->Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj_traits->Data,
      obj_traits,
      v8);
  v12 = v8 + t->Size;
  if ( v12 > t->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      t,
      t,
      v12);
  v13 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    Size = t->Size;
    v15 = obj_traits->Data.Size;
    v16 = v15 + 1;
    if ( v15 + 1 >= v15 )
    {
      if ( v16 <= obj_traits->Data.Policy.Capacity )
        goto LABEL_15;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= obj_traits->Data.Policy.Capacity >> 1 )
        goto LABEL_15;
      v17 = v15 + 1;
    }
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj_traits->Data,
      obj_traits,
      v17);
LABEL_15:
    obj_traits->Data.Size = v16;
    obj_traits->Data.Data[v16 - 1] = Size;
    LODWORD(p_meta_info) = 338;
    v18 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, void **, __int64, _QWORD *, _QWORD *))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            this,
            48i64,
            &p_meta_info,
            v32,
            v33,
            v34);
    v19 = (Scaleform::GFx::AS3::Abc::TraitInfo *)v18;
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
    v21 = t->Size;
    v22 = v21 + 1;
    if ( v21 + 1 >= v21 )
    {
      if ( v22 <= t->Policy.Capacity )
        goto LABEL_24;
      v23 = v22 + (v22 >> 2);
    }
    else
    {
      if ( v22 >= t->Policy.Capacity >> 1 )
        goto LABEL_24;
      v23 = v21 + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      t,
      t,
      v23);
LABEL_24:
    t->Size = v22;
    t->Data[v22 - 1] = (unsigned __int64)v19;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, (Scaleform::GFx::AS3::Abc::TraitInfo *)t->Data[t->Size - 1]) )
      break;
    if ( ++v13 >= v8 )
      return 1;
  }
  v24 = obj_traits->Data.Size;
  v25 = v24 - 1;
  if ( v24 - 1 >= v24 )
  {
    if ( v25 > obj_traits->Data.Policy.Capacity )
    {
      v26 = v25 + (v25 >> 2);
LABEL_32:
      Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        &obj_traits->Data,
        obj_traits,
        v26);
    }
  }
  else if ( v25 < obj_traits->Data.Policy.Capacity >> 1 )
  {
    v26 = v24 - 1;
    goto LABEL_32;
  }
  obj_traits->Data.Size = v25;
  v27 = (Scaleform::GFx::AS3::Abc::TraitInfo *)t->Data[t->Size - 1];
  p_meta_info = v27;
  if ( v27 )
  {
    p_meta_info = &v27->meta_info;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27->meta_info.info.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v27);
  }
  v28 = t->Size;
  v29 = v28 - 1;
  if ( v28 - 1 >= v28 )
  {
    if ( v29 > t->Policy.Capacity )
    {
      v30 = v29 + (v29 >> 2);
LABEL_40:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        t,
        t,
        v30);
    }
  }
  else if ( v29 < t->Policy.Capacity >> 1 )
  {
    v30 = v28 - 1;
    goto LABEL_40;
  }
  t->Size = v29;
  return 0;
}

// File Line: 679
// RVA: 0x80D9B0
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::HasCode *obj)
{
  const char *CP; // rax
  char v6; // r9
  unsigned int v8; // ecx
  int v9; // r11d
  char v10; // dl
  int v11; // eax

  CP = this->CP;
  v6 = *CP;
  this->CP = CP + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *this->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  obj->method_info_ind = v9;
  return Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, t, &obj->obj_traits) && obj->method_info_ind >= 0;
}

// File Line: 693
// RVA: 0x80DA40
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::Instance *obj)
{
  const char *CP; // rax
  char v6; // r9
  unsigned int v8; // ecx
  int v9; // r8d
  char v10; // dl
  int v11; // eax
  char v12; // cl
  bool v13; // sf
  bool v14; // al

  CP = this->CP;
  v6 = *CP;
  this->CP = CP + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *this->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  obj->name_ind = v9;
  v14 = 0;
  if ( Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->super_name_ind) )
  {
    v12 = *this->CP++;
    v13 = obj->name_ind < 0;
    obj->flags = v12;
    if ( !v13 && obj->super_name_ind >= 0 )
      v14 = 1;
  }
  if ( (obj->flags & 8) != 0 )
  {
    if ( !v14 || !Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->protected_namespace_ind) )
      return 0;
  }
  else if ( !v14 )
  {
    return 0;
  }
  return Scaleform::GFx::AS3::Abc::Reader::Read(
           this,
           (Scaleform::GFx::AS3::Abc::TraitInfo::MetaInfo *)&obj->implemented_interfaces)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, t, obj);
}

// File Line: 716
// RVA: 0x80D1C0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitInfo::MetaInfo *obj)
{
  const char *CP; // rax
  char v5; // r8
  unsigned int v6; // ecx
  int v7; // ebx
  char v8; // dl
  int v9; // eax
  __int64 i; // r14
  const char *v11; // rax
  unsigned int v12; // ecx
  char v13; // dl
  int v14; // esi
  char v15; // dl
  int v16; // eax
  unsigned __int64 Size; // rax
  unsigned __int64 v18; // rbx
  unsigned __int64 v19; // r8
  int *Data; // rax

  CP = this->CP;
  v5 = *CP;
  this->CP = CP + 1;
  v6 = 7;
  v7 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = *this->CP++;
      v9 = (v8 & 0x7F) << v6;
      v6 += 7;
      v7 |= v9;
    }
    while ( v8 < 0 );
  }
  if ( v7 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v7);
  if ( v7 > 0 )
  {
    for ( i = (unsigned int)v7; i; --i )
    {
      v11 = this->CP;
      v12 = 7;
      v13 = *v11;
      this->CP = v11 + 1;
      v14 = v13 & 0x7F;
      if ( v13 < 0 )
      {
        do
        {
          if ( v12 >= 0x20 )
            break;
          v15 = *this->CP++;
          v16 = (v15 & 0x7F) << v12;
          v12 += 7;
          v14 |= v16;
        }
        while ( v15 < 0 );
      }
      Size = obj->info.Data.Size;
      v18 = Size + 1;
      if ( Size + 1 >= Size )
      {
        if ( v18 > obj->info.Data.Policy.Capacity )
        {
          v19 = v18 + (v18 >> 2);
          goto LABEL_16;
        }
      }
      else if ( v18 < obj->info.Data.Policy.Capacity >> 1 )
      {
        v19 = Size + 1;
LABEL_16:
        Scaleform::ArrayDataBase<long,Scaleform::AllocatorLH_POD<long,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
          &obj->info.Data,
          obj,
          v19);
      }
      Data = obj->info.Data.Data;
      obj->info.Data.Size = v18;
      Data[v18 - 1] = v14;
    }
  }
  return 1;
}

// File Line: 739
// RVA: 0x80D6E0
_BOOL8 __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  const char *CP; // rax
  char v6; // r9
  int v7; // r15d
  unsigned int v8; // ecx
  const char *v9; // rax
  char v10; // dl
  bool v11; // bl
  __int64 v12; // rdi
  int i; // r12d
  __int64 v14; // rax
  Scaleform::GFx::AS3::Abc::ClassInfo *v15; // rbx
  unsigned __int64 Size; // rax
  unsigned __int64 v17; // rbp
  unsigned __int64 v18; // r8
  unsigned __int64 v19; // rcx
  Scaleform::GFx::AS3::Abc::ClassInfo *v20; // rbp
  unsigned __int64 v21; // rax
  unsigned __int64 v22; // rbp
  unsigned __int64 v23; // r8
  Scaleform::GFx::AS3::Abc::ClassInfo *v24; // rbp
  const char *v25; // rax
  char v26; // dl
  int v27; // r8d
  unsigned int v28; // ecx
  const char *v29; // rax
  char v30; // dl
  __int64 v32; // [rsp+20h] [rbp-78h]
  __int64 v33; // [rsp+28h] [rbp-70h]
  __int64 v34; // [rsp+30h] [rbp-68h]
  __int64 v35; // [rsp+38h] [rbp-60h]
  __int64 v36; // [rsp+40h] [rbp-58h]
  int v38; // [rsp+B0h] [rbp+18h] BYREF
  __int64 v39; // [rsp+B8h] [rbp+20h]

  v32 = -2i64;
  CP = this->CP;
  v6 = *CP;
  this->CP = CP + 1;
  v7 = v6 & 0x7F;
  v8 = 7;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v9 = this->CP;
      v10 = *v9;
      this->CP = v9 + 1;
      v7 |= (v10 & 0x7F) << v8;
      v8 += 7;
    }
    while ( v10 < 0 );
  }
  v11 = 1;
  if ( v7 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v7);
  v12 = 0i64;
  for ( i = 0; i < v7; ++i )
  {
    v38 = 338;
    v14 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, int *, __int64, __int64, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            this,
            104i64,
            &v38,
            v32,
            v33,
            v34,
            v35,
            v36);
    v15 = (Scaleform::GFx::AS3::Abc::ClassInfo *)v14;
    v39 = v14;
    if ( v14 )
    {
      v33 = v14;
      *(_QWORD *)v14 = 0i64;
      *(_QWORD *)(v14 + 8) = 0i64;
      *(_QWORD *)(v14 + 16) = 0i64;
      *(_DWORD *)(v14 + 24) = -1;
      *(_QWORD *)(v14 + 36) = -1i64;
      *(_DWORD *)(v14 + 44) = -1;
      *(_QWORD *)(v14 + 48) = 0i64;
      *(_QWORD *)(v14 + 56) = 0i64;
      *(_QWORD *)(v14 + 64) = 0i64;
      v36 = v14 + 72;
      v35 = v14 + 72;
      v34 = v14 + 72;
      *(_QWORD *)(v14 + 72) = 0i64;
      *(_QWORD *)(v14 + 80) = 0i64;
      *(_QWORD *)(v14 + 88) = 0i64;
      *(_DWORD *)(v14 + 96) = -1;
    }
    else
    {
      v15 = 0i64;
    }
    Size = obj->Size;
    v17 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v17 <= obj->Policy.Capacity )
        goto LABEL_17;
      v18 = v17 + (v17 >> 2);
    }
    else
    {
      if ( v17 >= obj->Policy.Capacity >> 1 )
        goto LABEL_17;
      v18 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v18);
LABEL_17:
    obj->Size = v17;
    obj->Data[v17 - 1] = (unsigned __int64)v15;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(
            this,
            t,
            (Scaleform::GFx::AS3::Abc::Instance *)obj->Data[obj->Size - 1]) )
    {
      v11 = 0;
      v19 = obj->Size;
      v20 = (Scaleform::GFx::AS3::Abc::ClassInfo *)obj->Data[v19 - 1];
      if ( v20 )
      {
        Scaleform::GFx::AS3::Abc::ClassInfo::~ClassInfo((Scaleform::GFx::AS3::Abc::ClassInfo *)obj->Data[v19 - 1]);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20);
      }
      v21 = obj->Size;
      v22 = v21 - 1;
      if ( v21 - 1 >= v21 )
      {
        if ( v22 > obj->Policy.Capacity )
        {
          v23 = v22 + (v22 >> 2);
LABEL_26:
          Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
            obj,
            obj,
            v23);
        }
      }
      else if ( v22 < obj->Policy.Capacity >> 1 )
      {
        v23 = v21 - 1;
        goto LABEL_26;
      }
      obj->Size = v22;
      break;
    }
    v11 = 1;
  }
  while ( v11 )
  {
    if ( v12 >= v7 )
      break;
    v24 = (Scaleform::GFx::AS3::Abc::ClassInfo *)obj->Data[v12];
    v25 = this->CP;
    v26 = *v25;
    this->CP = v25 + 1;
    v27 = v26 & 0x7F;
    v28 = 7;
    if ( v26 < 0 )
    {
      do
      {
        if ( v28 >= 0x20 )
          break;
        v29 = this->CP;
        v30 = *v29;
        this->CP = v29 + 1;
        v27 |= (v30 & 0x7F) << v28;
        v28 += 7;
      }
      while ( v30 < 0 );
    }
    v24->stat_info.method_info_ind = v27;
    v11 = Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, t, &v24->stat_info.obj_traits)
       && v24->stat_info.method_info_ind >= 0;
    ++v12;
  }
  return v11;
}

// File Line: 806
// RVA: 0x80DED0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  const char *CP; // rax
  char v7; // r8
  int v8; // ebp
  unsigned int v9; // ecx
  const char *v10; // rax
  char v11; // dl
  int v12; // r15d
  __int64 v13; // rax
  Scaleform::GFx::AS3::Abc::ScriptInfo *v14; // rdi
  unsigned __int64 Size; // rax
  unsigned __int64 v16; // rsi
  unsigned __int64 v17; // r8
  Scaleform::GFx::AS3::Abc::ScriptInfo *v18; // rdi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // rdi
  unsigned __int64 v21; // r8
  __int64 v23; // [rsp+20h] [rbp-58h]
  __int64 v24; // [rsp+28h] [rbp-50h]
  __int64 v25; // [rsp+30h] [rbp-48h]
  Scaleform::GFx::AS3::Abc::ScriptInfo *v26; // [rsp+90h] [rbp+18h] BYREF
  __int64 v27; // [rsp+98h] [rbp+20h]

  v23 = -2i64;
  CP = this->CP;
  v7 = *CP;
  this->CP = CP + 1;
  v8 = v7 & 0x7F;
  v9 = 7;
  if ( v7 < 0 )
  {
    do
    {
      if ( v9 >= 0x20 )
        break;
      v10 = this->CP;
      v11 = *v10;
      this->CP = v10 + 1;
      v8 |= (v11 & 0x7F) << v9;
      v9 += 7;
    }
    while ( v11 < 0 );
  }
  if ( v8 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v8);
  v12 = 0;
  if ( v8 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v26) = 338;
    v13 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, Scaleform::GFx::AS3::Abc::ScriptInfo **, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            this,
            32i64,
            &v26,
            v23,
            v24,
            v25);
    v14 = (Scaleform::GFx::AS3::Abc::ScriptInfo *)v13;
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
    Size = obj->Size;
    v16 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v16 <= obj->Policy.Capacity )
        goto LABEL_16;
      v17 = v16 + (v16 >> 2);
    }
    else
    {
      if ( v16 >= obj->Policy.Capacity >> 1 )
        goto LABEL_16;
      v17 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v17);
LABEL_16:
    obj->Size = v16;
    obj->Data[v16 - 1] = (unsigned __int64)v14;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, t, (Scaleform::GFx::AS3::Abc::HasCode *)obj->Data[obj->Size - 1]) )
      break;
    if ( ++v12 >= v8 )
      return 1;
  }
  v18 = (Scaleform::GFx::AS3::Abc::ScriptInfo *)obj->Data[obj->Size - 1];
  v26 = v18;
  if ( v18 )
  {
    v26 = v18;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18->obj_traits.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v18);
  }
  v19 = obj->Size;
  v20 = v19 - 1;
  if ( v19 - 1 >= v19 )
  {
    if ( v20 > obj->Policy.Capacity )
    {
      v21 = v20 + (v20 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        v21);
    }
  }
  else if ( v20 < obj->Policy.Capacity >> 1 )
  {
    v21 = v19 - 1;
    goto LABEL_26;
  }
  obj->Size = v20;
  return 0;
}

// File Line: 831
// RVA: 0x80C1D0
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::Code *obj)
{
  const char *CP; // rax
  char v4; // dl
  unsigned int v5; // ecx
  int v6; // r9d
  char v7; // dl
  int v8; // eax

  obj->code.Data = this->CP;
  CP = this->CP;
  v4 = *CP;
  this->CP = CP + 1;
  v5 = 7;
  v6 = v4 & 0x7F;
  if ( v4 < 0 )
  {
    do
    {
      if ( v5 >= 0x20 )
        break;
      v7 = *this->CP++;
      v8 = (v7 & 0x7F) << v5;
      v5 += 7;
      v6 |= v8;
    }
    while ( v7 < 0 );
  }
  this->CP += v6;
  return 1;
}

// File Line: 844
// RVA: 0x80DB40
bool __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo *obj)
{
  const char *CP; // rax
  char v6; // r9
  unsigned int v8; // ecx
  int v9; // r8d
  char v10; // dl
  int v11; // eax

  CP = this->CP;
  v6 = *CP;
  this->CP = CP + 1;
  v8 = 7;
  v9 = v6 & 0x7F;
  if ( v6 < 0 )
  {
    do
    {
      if ( v8 >= 0x20 )
        break;
      v10 = *this->CP++;
      v11 = (v10 & 0x7F) << v8;
      v8 += 7;
      v9 |= v11;
    }
    while ( v10 < 0 );
  }
  obj->method_info_ind = v9;
  return Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->max_stack)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->local_reg_count)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->init_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, (unsigned int *)&obj->max_scope_depth)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->code)
      && Scaleform::GFx::AS3::Abc::Reader::Read(this, &obj->exception)
      && Scaleform::GFx::AS3::Abc::Reader::ReadTraits(this, t, &obj->obj_traits)
      && obj->method_info_ind >= 0;
}

// File Line: 878
// RVA: 0x80CE90
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::MethodBodyInfo::Exception *obj)
{
  const char *CP; // rax
  char v5; // cl
  unsigned int v6; // r8d
  int v7; // ebp
  const char *v8; // rax
  char v9; // cl
  char v10; // dl
  int v11; // r14d
  const char *v12; // rax
  char v13; // cl
  unsigned int v14; // r8d
  int v15; // r9d
  const char *v16; // rax
  char v17; // cl
  char v18; // dl
  const char *v19; // rax
  unsigned int v20; // r8d
  char v21; // cl
  int v22; // r9d
  const char *v23; // rax
  char v24; // cl
  char v25; // dl
  unsigned __int64 Size; // rax
  unsigned __int64 v27; // rdi
  unsigned __int64 v28; // r8
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *Data; // rax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo *v30; // rdx
  int v32; // [rsp+20h] [rbp-38h]
  int v33; // [rsp+24h] [rbp-34h]
  unsigned int v[2]; // [rsp+28h] [rbp-30h] BYREF
  unsigned int v35[10]; // [rsp+30h] [rbp-28h] BYREF

  CP = this->CP;
  v5 = *CP;
  v6 = 7;
  this->CP = CP + 1;
  v7 = v5 & 0x7F;
  if ( v5 < 0 )
  {
    do
    {
      if ( v6 >= 0x20 )
        break;
      v8 = this->CP;
      v9 = v6;
      v6 += 7;
      v10 = *v8;
      this->CP = v8 + 1;
      v7 |= (v10 & 0x7F) << v9;
    }
    while ( v10 < 0 );
  }
  if ( v7 > obj->info.Data.Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v7);
  v11 = 0;
  while ( v11 < v7 )
  {
    v12 = this->CP;
    *(_QWORD *)v = 0i64;
    v35[0] = 0;
    v13 = *v12;
    v14 = 7;
    this->CP = v12 + 1;
    v15 = v13 & 0x7F;
    if ( v13 < 0 )
    {
      do
      {
        if ( v14 >= 0x20 )
          break;
        v16 = this->CP;
        v17 = v14;
        v14 += 7;
        v18 = *v16;
        this->CP = v16 + 1;
        v15 |= (v18 & 0x7F) << v17;
      }
      while ( v18 < 0 );
    }
    v19 = this->CP;
    v32 = v15;
    v20 = 7;
    v21 = *v19;
    this->CP = v19 + 1;
    v22 = v21 & 0x7F;
    if ( v21 < 0 )
    {
      do
      {
        if ( v20 >= 0x20 )
          break;
        v23 = this->CP;
        v24 = v20;
        v20 += 7;
        v25 = *v23;
        this->CP = v23 + 1;
        v22 |= (v25 & 0x7F) << v24;
      }
      while ( v25 < 0 );
    }
    v33 = v22;
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, v)
      || !Scaleform::GFx::AS3::Abc::Reader::Read(this, &v[1])
      || !Scaleform::GFx::AS3::Abc::Reader::Read(this, v35) )
    {
      return 0;
    }
    Size = obj->info.Data.Size;
    v27 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v27 <= obj->info.Data.Policy.Capacity )
        goto LABEL_23;
      v28 = v27 + (v27 >> 2);
    }
    else
    {
      if ( v27 >= obj->info.Data.Policy.Capacity >> 1 )
        goto LABEL_23;
      v28 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS3::Abc::MethodBodyInfo::ExceptionInfo,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      &obj->info.Data,
      obj,
      v28);
LABEL_23:
    Data = obj->info.Data.Data;
    obj->info.Data.Size = v27;
    v30 = &Data[v27];
    ++v11;
    v30[-1].from = v32;
    v30[-1].to = v33;
    v30[-1].target = v[0];
    v30[-1].exc_type_ind = v[1];
    v30[-1].var_name_ind = v35[0];
  }
  return 1;
}

// File Line: 900
// RVA: 0x80DC40
char __fastcall Scaleform::GFx::AS3::Abc::Reader::Read(
        Scaleform::GFx::AS3::Abc::Reader *this,
        Scaleform::GFx::AS3::Abc::TraitTable *t,
        Scaleform::GFx::AS3::Abc::MethodTable *mt,
        Scaleform::ArrayDataBase<unsigned __int64,Scaleform::AllocatorLH_POD<unsigned __int64,338>,Scaleform::ArrayDefaultPolicy> *obj)
{
  const char *CP; // rax
  char v9; // r10
  int v10; // ebp
  unsigned int v11; // ecx
  const char *v12; // rax
  char v13; // dl
  int v14; // r15d
  __int64 v15; // rax
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v16; // rdi
  unsigned __int64 Size; // rax
  unsigned __int64 v18; // rsi
  unsigned __int64 v19; // r8
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v20; // rdi
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v21; // rdi
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // rdi
  unsigned __int64 v24; // r8
  __int64 v26; // [rsp+20h] [rbp-68h]
  __int64 v27; // [rsp+28h] [rbp-60h]
  __int64 v28; // [rsp+30h] [rbp-58h]
  __int64 v29; // [rsp+38h] [rbp-50h]
  __int64 v30; // [rsp+40h] [rbp-48h]
  Scaleform::GFx::AS3::Abc::MethodBodyInfo *v31; // [rsp+A8h] [rbp+20h] BYREF

  v26 = -2i64;
  CP = this->CP;
  v9 = *CP;
  this->CP = CP + 1;
  v10 = v9 & 0x7F;
  v11 = 7;
  if ( v9 < 0 )
  {
    do
    {
      if ( v11 >= 0x20 )
        break;
      v12 = this->CP;
      v13 = *v12;
      this->CP = v12 + 1;
      v10 |= (v13 & 0x7F) << v11;
      v11 += 7;
    }
    while ( v13 < 0 );
  }
  if ( v10 > obj->Policy.Capacity )
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v10);
  v14 = 0;
  if ( v10 <= 0 )
    return 1;
  while ( 1 )
  {
    LODWORD(v31) = 338;
    v15 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::AS3::Abc::Reader *, __int64, Scaleform::GFx::AS3::Abc::MethodBodyInfo **, __int64, __int64, __int64, __int64, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
            Scaleform::Memory::pGlobalHeap,
            this,
            88i64,
            &v31,
            v26,
            v27,
            v28,
            v29,
            v30);
    v16 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)v15;
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
      v29 = v15 + 64;
      v28 = v15 + 64;
      v30 = v15 + 64;
      *(_QWORD *)(v15 + 64) = 0i64;
      *(_QWORD *)(v15 + 72) = 0i64;
      *(_QWORD *)(v15 + 80) = 0i64;
    }
    else
    {
      v16 = 0i64;
    }
    Size = obj->Size;
    v18 = Size + 1;
    if ( Size + 1 >= Size )
    {
      if ( v18 <= obj->Policy.Capacity )
        goto LABEL_16;
      v19 = v18 + (v18 >> 2);
    }
    else
    {
      if ( v18 >= obj->Policy.Capacity >> 1 )
        goto LABEL_16;
      v19 = Size + 1;
    }
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
      obj,
      obj,
      v19);
LABEL_16:
    obj->Size = v18;
    obj->Data[v18 - 1] = (unsigned __int64)v16;
    v20 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)obj->Data[obj->Size - 1];
    if ( !Scaleform::GFx::AS3::Abc::Reader::Read(this, t, v20) )
      break;
    mt->Info.Data.Data[v20->method_info_ind]->MethodBodyInfoInd = v14++;
    if ( v14 >= v10 )
      return 1;
  }
  v21 = (Scaleform::GFx::AS3::Abc::MethodBodyInfo *)obj->Data[obj->Size - 1];
  v31 = v21;
  if ( v21 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21->exception.info.Data.Data);
    v21->code.vfptr = (Scaleform::GFx::AS3::Abc::CodeVtbl *)&Scaleform::GFx::AS3::Abc::Code::`vftable;
    v31 = v21;
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21->obj_traits.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v21);
  }
  v22 = obj->Size;
  v23 = v22 - 1;
  if ( v22 - 1 >= v22 )
  {
    if ( v23 > obj->Policy.Capacity )
    {
      v24 = v23 + (v23 >> 2);
LABEL_26:
      Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Abc::MetadataInfo::Item,338>,Scaleform::ArrayDefaultPolicy>::Reserve(
        obj,
        obj,
        v24);
    }
  }
  else if ( v23 < obj->Policy.Capacity >> 1 )
  {
    v24 = v22 - 1;
    goto LABEL_26;
  }
  obj->Size = v23;
  return 0;
}

