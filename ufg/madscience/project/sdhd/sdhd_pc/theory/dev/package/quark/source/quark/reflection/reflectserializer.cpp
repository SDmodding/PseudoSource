// File Line: 20
// RVA: 0x17E7B0
void __fastcall UFG::qReflectVisitor::TrackObject(UFG::qReflectVisitor *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  const char *v3; // rbx
  UFG::qReflectVisitor *v4; // rsi
  unsigned __int64 v5; // rdi
  UFG::ReflectionDB *v6; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v7; // r8
  __int64 v8; // r9
  unsigned int v9; // er10
  UFG::qReflectVisitor::ObjectData *v10; // r11
  __int64 v11; // r9
  unsigned int v12; // er11
  UFG::qReflectVisitor::ArrayData *v13; // rdi
  unsigned __int64 v14; // rdx
  __int64 v15; // rdi
  unsigned int v16; // ebx
  unsigned int v17; // edx
  unsigned int v18; // edx
  signed __int64 v19; // rbx
  __int64 *v20; // rcx
  __int64 **v21; // rax
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v22; // [rsp+28h] [rbp-9h]
  const char *v23; // [rsp+30h] [rbp-1h]
  __int64 *v24; // [rsp+38h] [rbp+7h]
  __int64 **v25; // [rsp+40h] [rbp+Fh]
  int length[2]; // [rsp+48h] [rbp+17h]
  char *text; // [rsp+50h] [rbp+1Fh]
  __int64 v28; // [rsp+58h] [rbp+27h]
  __int64 v29; // [rsp+60h] [rbp+2Fh]
  __int64 v30; // [rsp+68h] [rbp+37h]
  __int64 **retaddr; // [rsp+A8h] [rbp+77h]

  if ( object_data )
  {
    v3 = object_data;
    v4 = this;
    if ( reflection_type->mFlags & 0x10 )
    {
      v5 = *((_QWORD *)object_data + 7);
      v6 = UFG::ReflectionDB::Instance();
      v7 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v6->mTypes.mTree.mHead.mChildren[0];
      while ( v7 != &v6->mTypes )
      {
        if ( v7->mTree.mHead.mUID >= v5 )
        {
          if ( v7->mTree.mHead.mUID <= v5 )
            goto LABEL_10;
          v7 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v7->mTree.mHead.mChildren[0];
        }
        else
        {
          v7 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v7->mTree.mHead.mChildren[1];
        }
      }
      v7 = 0i64;
LABEL_10:
      v8 = 0i64;
      v9 = v4->mTrackedObjects.size;
      if ( v9 )
      {
        v10 = v4->mTrackedObjects.p;
        while ( v3 < v10[v8].mObjectData || v3 >= &v10[v8].mObjectData[v10[v8].mReflectionType->mNumBytes] )
        {
          v8 = (unsigned int)(v8 + 1);
          if ( (unsigned int)v8 >= v9 )
            goto LABEL_15;
        }
      }
      else
      {
LABEL_15:
        v11 = 0i64;
        v12 = v4->mArrays.size;
        if ( v12 )
        {
          v13 = v4->mArrays.p;
          while ( 1 )
          {
            v14 = (unsigned __int64)*v13[v11].mArrayLocation;
            if ( (unsigned __int64)v3 >= v14
              && (unsigned __int64)v3 < v14 + v13[v11].mArraySize * v13[v11].mSubType->mNumBytes )
            {
              break;
            }
            v11 = (unsigned int)(v11 + 1);
            if ( (unsigned int)v11 >= v12 )
              goto LABEL_20;
          }
        }
        else
        {
LABEL_20:
          retaddr = &v24;
          v24 = (__int64 *)&v24;
          v25 = &v24;
          *(_QWORD *)length = 16909060i64;
          text = (char *)UFG::qString::sEmptyString;
          v28 = -1i64;
          v22 = v7;
          v23 = v3;
          v15 = v4->mTrackedObjects.size;
          v16 = v15 + 1;
          v17 = v4->mTrackedObjects.capacity;
          if ( (signed int)v15 + 1 > v17 )
          {
            if ( v17 )
              v18 = 2 * v17;
            else
              v18 = 1;
            for ( ; v18 < v16; v18 *= 2 )
              ;
            if ( v18 - v16 > 0x10000 )
              v18 = v15 + 65537;
            UFG::qArray<UFG::qReflectVisitor::ObjectData,0>::Reallocate(&v4->mTrackedObjects, v18, "qArray.Add");
            v7 = v22;
          }
          v4->mTrackedObjects.size = v16;
          v19 = (signed __int64)&v4->mTrackedObjects.p[v15];
          *(_QWORD *)v19 = v7;
          *(_QWORD *)(v19 + 8) = v23;
          UFG::qString::Set((UFG::qString *)(v19 + 16), text, length[1], 0i64, 0);
          *(_QWORD *)(v19 + 56) = v29;
          *(_QWORD *)(v19 + 64) = v30;
          retaddr = &v24;
          if ( text != UFG::qString::sEmptyString )
          {
            if ( text )
              UFG::qMemoryPool::Free(UFG::gMainMemoryPool, text);
          }
          v20 = v24;
          v21 = v25;
          v24[1] = (__int64)v25;
          *v21 = v20;
        }
      }
    }
  }
}

// File Line: 68
// RVA: 0x17D090
void __fastcall UFG::qReflectVisitor::SetObjectName(UFG::qReflectVisitor *this, unsigned int index, UFG::qString *name)
{
  UFG::qString::Set(
    (UFG::qString *)(&this->mTrackedObjects.p->mReflectionType + 9i64 * index + 2),
    name->mData,
    name->mLength,
    0i64,
    0);
}

// File Line: 73
// RVA: 0x166680
void __fastcall UFG::qReflectVisitor::AddPointerPatch(UFG::qReflectVisitor *this, UFG::qReflectType *object_type, UFG::qReflectField *field, unsigned int array_index, UFG::qReflectType *reflection_type, const char **pointer, const char *data)
{
  UFG::qArray<UFG::qReflectVisitor::PointerPatch,0> *v7; // rsi
  __int64 v8; // rdi
  unsigned int v9; // er10
  const char **v10; // rax
  unsigned int v11; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  UFG::qReflectVisitor::PointerPatch *v14; // rax
  __int64 v15; // rcx
  __int128 v16; // [rsp+20h] [rbp-48h]
  __int128 v17; // [rsp+30h] [rbp-38h]
  __int128 v18; // [rsp+50h] [rbp-18h]

  if ( pointer && *pointer )
  {
    v7 = &this->mPatches;
    v8 = this->mPatches.size;
    v9 = 0;
    if ( (_DWORD)v8 )
    {
      v10 = &this->mPatches.p->mObject;
      while ( __PAIR__((unsigned __int64)data, (unsigned __int64)pointer) != *(_OWORD *)(v10 - 1) )
      {
        ++v9;
        v10 += 8;
        if ( v9 >= (unsigned int)v8 )
          goto LABEL_7;
      }
    }
    else
    {
LABEL_7:
      *(_QWORD *)&v16 = object_type;
      v11 = this->mPatches.capacity;
      *((_QWORD *)&v16 + 1) = field;
      v12 = v8 + 1;
      LODWORD(v17) = array_index;
      *((_QWORD *)&v17 + 1) = reflection_type;
      if ( (signed int)v8 + 1 > v11 )
      {
        if ( v11 )
          v13 = 2 * v11;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 - v12 > 0x10000 )
          v13 = v8 + 65537;
        UFG::qArray<UFG::qReflectVisitor::PointerPatch,0>::Reallocate(&this->mPatches, v13, "qArray.Add");
      }
      v14 = v7->p;
      v7->size = v12;
      v15 = v8 << 6;
      *(_OWORD *)((char *)&v14->mObjectType + v15) = v16;
      *(_OWORD *)((char *)&v14->mArrayIndex + v15) = v17;
      *(_OWORD *)((char *)&v14->mPointer + v15) = __PAIR__((unsigned __int64)data, (unsigned __int64)pointer);
      *(_OWORD *)((char *)&v14->mPointerId + v15) = v18;
    }
  }
}

// File Line: 110
// RVA: 0x17F9C0
void __fastcall UFG::qReflectVisitor::VisitObjects(UFG::qReflectVisitor *this)
{
  UFG::qReflectVisitor *v1; // rdi
  UFG::ReflectionDB *v2; // rax
  const char *v3; // r10
  unsigned __int64 v4; // r9
  char v5; // cl
  __int64 v6; // r8
  signed __int64 v7; // rdx
  UFG::qTree64Base::BaseNode *v8; // rax
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rsi
  signed __int64 v11; // rbx
  unsigned __int64 v12; // r14
  signed __int64 v13; // rbx
  __int64 v14; // rsi
  UFG::qReflectField *v15; // rdx
  unsigned int v16; // eax
  signed __int64 v17; // rbp
  UFG::ReflectionDB *v18; // rax
  const char *v19; // r8
  unsigned __int64 v20; // r9
  char v21; // cl
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *v22; // r8

  v1 = this;
  v2 = UFG::ReflectionDB::Instance();
  v3 = "pointer";
  v4 = -1i64;
  v5 = 112;
  do
  {
    ++v3;
    v6 = (unsigned __int8)(v4 ^ v5);
    v4 = (v4 >> 8) ^ sCrcTable64[v6];
    v5 = *v3;
  }
  while ( *v3 );
  v7 = (signed __int64)&v2->mTypes;
  v8 = v2->mTypes.mTree.mHead.mChildren[0];
  while ( v8 != (UFG::qTree64Base::BaseNode *)v7 )
  {
    if ( v8->mUID >= v4 )
    {
      if ( v8->mUID <= v4 )
        break;
      v8 = v8->mChildren[0];
    }
    else
    {
      v8 = v8->mChildren[1];
    }
  }
  v9 = 0i64;
  if ( v1->mTrackedObjects.size )
  {
    do
    {
      UFG::qReflectVisitor::DiscoverObject(
        v1,
        v1->mTrackedObjects.p[(unsigned int)v9].mReflectionType,
        v1->mTrackedObjects.p[(unsigned int)v9].mObjectData);
      ++v9;
    }
    while ( v9 < v1->mTrackedObjects.size );
  }
  ((void (__fastcall *)(UFG::qReflectVisitor *, signed __int64, __int64, unsigned __int64))v1->vfptr->BeginVisit)(
    v1,
    v7,
    v6,
    v4);
  v10 = 0i64;
  if ( v1->mTrackedObjects.size )
  {
    do
    {
      v11 = (signed __int64)&v1->mTrackedObjects.p[(unsigned int)v10];
      v1->vfptr->AlignTo(v1, *(_DWORD *)(*(_QWORD *)v11 + 88i64));
      UFG::qReflectVisitor::VisitObject(v1, *(UFG::qReflectType **)v11, *(const char **)(v11 + 8));
      ++v10;
    }
    while ( v10 < v1->mTrackedObjects.size );
  }
  v12 = 0i64;
  if ( v1->mArrays.size )
  {
    do
    {
      v13 = (signed __int64)&v1->mArrays.p[(unsigned int)v12];
      v1->vfptr->AlignTo(v1, *(_DWORD *)(*(_QWORD *)(v13 + 24) + 88i64));
      if ( v1->vfptr->BeginArray(v1, (UFG::qReflectVisitor::ArrayData *)v13) )
      {
        v14 = 0i64;
        if ( *(_DWORD *)(v13 + 32) )
        {
          do
          {
            v15 = *(UFG::qReflectField **)(v13 + 8);
            v16 = v15->mFlags;
            if ( _bittest((const signed int *)&v16, 0xEu) )
            {
              v17 = **(_QWORD **)(v13 + 40) + 8 * v14;
              v1->vfptr->BeginPointer(v1, *(UFG::qReflectType **)(v13 + 24), (const char *)v17);
              v18 = UFG::ReflectionDB::Instance();
              v19 = "pointer";
              v20 = -1i64;
              v21 = 112;
              do
              {
                ++v19;
                v20 = (v20 >> 8) ^ sCrcTable64[(unsigned __int8)(v20 ^ v21)];
                v21 = *v19;
              }
              while ( *v19 );
              v22 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v18->mTypes.mTree.mHead.mChildren[0];
              while ( v22 != &v18->mTypes )
              {
                if ( v22->mTree.mHead.mUID >= v20 )
                {
                  if ( v22->mTree.mHead.mUID <= v20 )
                    goto LABEL_26;
                  v22 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v22->mTree.mHead.mChildren[0];
                }
                else
                {
                  v22 = (UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *)v22->mTree.mHead.mChildren[1];
                }
              }
              v22 = 0i64;
LABEL_26:
              v1->vfptr->BeginPointer(
                v1,
                *(UFG::qReflectField **)(v13 + 8),
                (UFG::qReflectType *)v22,
                (const char *)v17);
              v1->vfptr->EndPointer(v1, *(UFG::qReflectType **)(v13 + 24), (const char *)v17);
            }
            else if ( v16 & 1 )
            {
              v1->vfptr->BeginBytes(
                v1,
                v15,
                *(UFG::qReflectType **)(v13 + 24),
                (const char *)(**(_QWORD **)(v13 + 40)
                             + (~(*(unsigned int *)(*(_QWORD *)(v13 + 24) + 88i64) - 1i64) & (*(unsigned int *)(*(_QWORD *)(v13 + 24) + 88i64)
                                                                                            + (unsigned int)v14
                                                                                            * *(_QWORD *)(*(_QWORD *)(v13 + 24) + 80i64)
                                                                                            - 1i64))));
            }
            else
            {
              UFG::qReflectVisitor::VisitObject(
                v1,
                *(UFG::qReflectType **)(v13 + 24),
                (const char *)(**(_QWORD **)(v13 + 40)
                             + (~(*(unsigned int *)(*(_QWORD *)(v13 + 24) + 88i64) - 1i64) & (*(unsigned int *)(*(_QWORD *)(v13 + 24) + 88i64)
                                                                                            + (unsigned int)v14
                                                                                            * *(_QWORD *)(*(_QWORD *)(v13 + 24) + 80i64)
                                                                                            - 1i64))));
            }
            v14 = (unsigned int)(v14 + 1);
          }
          while ( (unsigned int)v14 < *(_DWORD *)(v13 + 32) );
        }
        v1->vfptr->EndArray(v1, (UFG::qReflectVisitor::ArrayData *)v13);
      }
      ++v12;
    }
    while ( v12 < v1->mArrays.size );
  }
  v1->vfptr->EndVisit(v1);
}

// File Line: 178
// RVA: 0x16C9B0
void __fastcall UFG::qReflectVisitor::DiscoverObject(UFG::qReflectVisitor *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v3; // rbp
  const char *v4; // rsi
  UFG::qReflectVisitor *v5; // rdi
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v6; // rbx
  UFG::ReflectionDB *v7; // rax
  unsigned __int64 v8; // rdx
  UFG::ReflectionDB *v9; // r8
  char v10; // al
  UFG::qTree64Base::BaseNode *v11; // rbx
  int v12; // eax
  const char **pointer; // rsi
  UFG::qReflectField *v14; // rax
  unsigned __int64 v15; // rbp
  UFG::qTree64Base::BaseNode *v16; // rsi
  UFG::ReflectionDB *v17; // rax
  UFG::qReflectType *v18; // rax
  __int64 v19; // rcx
  UFG::qReflectType *v20; // rbp
  char *v21; // rsi
  unsigned int v22; // ecx
  UFG::qReflectField *v23; // r10
  unsigned int v24; // ebx
  unsigned int v25; // eax
  __int64 v26; // rcx
  const char **v27; // rsi
  const char *v28; // rdi
  char *data; // ST30_8
  const char *v30; // rsi
  bool v31; // cf
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v32; // rsi
  UFG::qReflectField *field; // [rsp+40h] [rbp-B8h]
  UFG::qReflectField *v34; // [rsp+48h] [rbp-B0h]
  char **v35; // [rsp+50h] [rbp-A8h]
  UFG::qTree64Base::BaseNode *i; // [rsp+58h] [rbp-A0h]
  char *v37; // [rsp+60h] [rbp-98h]
  __int64 v38; // [rsp+68h] [rbp-90h]
  __int64 v39; // [rsp+70h] [rbp-88h]
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *v40; // [rsp+78h] [rbp-80h]
  UFG::qReflectVisitor::ArrayData item; // [rsp+80h] [rbp-78h]
  UFG::qReflectVisitor *v42; // [rsp+100h] [rbp+8h]
  UFG::qReflectType *object_type; // [rsp+108h] [rbp+10h]
  const char *v44; // [rsp+110h] [rbp+18h]
  unsigned int v45; // [rsp+118h] [rbp+20h]

  v44 = object_data;
  object_type = reflection_type;
  v42 = this;
  v3 = reflection_type->mOrderedFields.mNode.mNext;
  v4 = object_data;
  v5 = this;
  field = (UFG::qReflectField *)v3;
  v40 = &reflection_type->mOrderedFields;
  if ( v3 != (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&reflection_type->mOrderedFields )
  {
    while ( 1 )
    {
      v6 = v3[4].mNext;
      v7 = UFG::ReflectionDB::Instance();
      v8 = -1i64;
      v9 = v7;
      if ( v6 )
      {
        v10 = (char)v6->mPrev;
        if ( LOBYTE(v6->mPrev) )
        {
          do
          {
            v6 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)((char *)v6 + 1);
            v8 = (v8 >> 8) ^ sCrcTable64[(unsigned __int8)(v8 ^ v10)];
            v10 = (char)v6->mPrev;
          }
          while ( LOBYTE(v6->mPrev) );
          v4 = v44;
        }
      }
      v11 = v9->mTypes.mTree.mHead.mChildren[0];
      for ( i = v11; v11 != (UFG::qTree64Base::BaseNode *)&v9->mTypes; i = v11 )
      {
        if ( v11->mUID >= v8 )
        {
          if ( v11->mUID <= v8 )
            goto LABEL_13;
          v11 = v11->mChildren[0];
        }
        else
        {
          v11 = v11->mChildren[1];
        }
      }
      v11 = 0i64;
      i = 0i64;
LABEL_13:
      v35 = (char **)&v4[(unsigned __int64)v3[6].mPrev];
      (*(void (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))&v5->vfptr->gap8[16])(
        v5,
        v3,
        v11,
        v35);
      v12 = (int)v3[7].mPrev;
      if ( v12 & 0x40 )
        goto LABEL_39;
      if ( _bittest(&v12, 0xDu) )
      {
        pointer = (const char **)v35;
        if ( !(*(unsigned __int8 (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))&v5->vfptr->gap8[8])(
                v5,
                v3,
                v11,
                v35) )
        {
LABEL_38:
          v4 = v44;
          goto LABEL_39;
        }
        v14 = field;
        v15 = 0i64;
        if ( field->mArrayLength )
        {
          do
          {
            if ( BYTE4(v11[1].mNeighbours[1]) & 0x10 )
            {
              UFG::qReflectVisitor::TrackObject(v5, (UFG::qReflectType *)v11, *pointer);
              UFG::qReflectVisitor::AddPointerPatch(
                v5,
                object_type,
                field,
                v15,
                (UFG::qReflectType *)v11,
                pointer,
                *pointer);
              v14 = field;
            }
            ++v15;
            ++pointer;
          }
          while ( v15 < v14->mArrayLength );
          v3 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&field->mPrev;
          goto LABEL_38;
        }
LABEL_37:
        v3 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&v14->mPrev;
        goto LABEL_38;
      }
      if ( !(v12 & 0x20) )
      {
        if ( v12 & 1
          || !v5->vfptr->DiscoverObjectField(v5, (UFG::qReflectField *)v3, (UFG::qReflectType *)v11, (const char *)v35) )
        {
          goto LABEL_39;
        }
        v32 = 0i64;
        if ( v3[6].mNext )
        {
          do
          {
            UFG::qReflectVisitor::DiscoverObject(
              v5,
              (UFG::qReflectType *)v11,
              (const char *)v35 + (_QWORD)v32 * (_QWORD)v11[1].mNeighbours[0]);
            v32 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)((char *)v32 + 1);
          }
          while ( v32 < v3[6].mNext );
        }
        goto LABEL_38;
      }
      if ( (*(unsigned __int8 (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))v5->vfptr->gap8)(
             v5,
             v3,
             v11,
             v35) )
      {
        break;
      }
LABEL_39:
      v5->vfptr->EndDiscoverField(v5, (UFG::qReflectField *)v3, (UFG::qReflectType *)v11, (const char *)v35);
      v3 = v3->mNext;
      field = (UFG::qReflectField *)v3;
      if ( v3 == (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)v40 )
        return;
    }
    v16 = v11[3].mChildren[1];
    v34 = (UFG::qReflectField *)v11[3].mChildren[1];
    v17 = UFG::ReflectionDB::Instance();
    v18 = UFG::ReflectionDB::GetType(v17, (const char *)v16[1].mChildren[1]);
    v19 = 0i64;
    v20 = v18;
    v14 = field;
    v39 = 0i64;
    if ( !field->mArrayLength )
      goto LABEL_37;
    while ( 1 )
    {
      v21 = (char *)v35 + v19 * (_QWORD)v11[1].mNeighbours[0];
      v37 = v21;
      v22 = *((_DWORD *)v21 + 2);
      v45 = v22;
      if ( v22 )
      {
        item.mOwnerField = v14;
        item.mArrayData = *(const char **)v21;
        item.mArrayField = v34;
        item.mArraySize = v22;
        item.mArrayType = object_type;
        item.mArrayLocation = (const char **)v21;
        item.mSubType = v20;
        UFG::qArray<UFG::qReflectVisitor::ArrayData,0>::Add(&v5->mArrays, &item, "qArray.Add");
        v23 = v34;
        if ( !(v34->mFlags & 1) )
        {
          v24 = 0;
          if ( v45 )
          {
            v25 = v45;
            v26 = 0i64;
            v38 = 0i64;
            while ( v23->mFlags & 0x4000 )
            {
              if ( v20->mFlags & 0x10 )
              {
                v27 = (const char **)(v26 + *(_QWORD *)v21);
                v28 = *v27;
                UFG::qReflectVisitor::TrackObject(v42, v20, *v27);
                data = (char *)v28;
                v5 = v42;
                UFG::qReflectVisitor::AddPointerPatch(v42, object_type, v34, v24, v20, v27, data);
LABEL_33:
                v26 = v38;
                v21 = v37;
                v23 = v34;
                v25 = v45;
              }
              v26 += 8i64;
              ++v24;
              v38 = v26;
              if ( v24 >= v25 )
                goto LABEL_35;
            }
            v30 = (const char *)(*(_QWORD *)v37
                               + (~(v20->mAlignment - 1i64) & (v20->mAlignment + v24 * v20->mNumBytes - 1)));
            if ( v5->vfptr->DiscoverObjectField(v5, v23, v20, v30) )
              UFG::qReflectVisitor::DiscoverObject(v5, v20, v30);
            goto LABEL_33;
          }
LABEL_35:
          v11 = i;
        }
      }
      v31 = v39++ + 1 < field->mArrayLength;
      v14 = field;
      v19 = v39;
      if ( !v31 )
        goto LABEL_37;
    }
  }
}

// File Line: 278
// RVA: 0x17F690
void __fastcall UFG::qReflectVisitor::VisitObject(UFG::qReflectVisitor *this, UFG::qReflectType *reflection_type, const char *object_data)
{
  const char *v3; // rdi
  UFG::qReflectType *v4; // rbx
  UFG::qReflectVisitor *v5; // rsi
  UFG::qReflectField *v6; // rbp
  unsigned __int64 v7; // rcx
  const char *v8; // rbx
  UFG::ReflectionDB *v9; // rax
  unsigned __int64 v10; // rdx
  UFG::ReflectionDB *v11; // r8
  char v12; // al
  UFG::qReflectType *v13; // rbx
  const char *v14; // rdi
  unsigned __int64 v15; // rdx
  unsigned __int64 v16; // ST20_8
  unsigned int v17; // eax
  unsigned __int64 v18; // rax
  const char *v19; // rdi
  bool v20; // zf
  UFG::qReflectVisitorVtbl *v21; // rax
  unsigned __int64 v22; // rdi
  unsigned __int64 v23; // [rsp+20h] [rbp-48h]
  unsigned __int64 v24; // [rsp+20h] [rbp-48h]
  signed __int64 v25; // [rsp+30h] [rbp-38h]
  unsigned __int64 v26; // [rsp+70h] [rbp+8h]
  UFG::qReflectType *v27; // [rsp+78h] [rbp+10h]
  const char *v28; // [rsp+80h] [rbp+18h]
  const char *v29; // [rsp+88h] [rbp+20h]

  v28 = object_data;
  v27 = reflection_type;
  v3 = object_data;
  v4 = reflection_type;
  v5 = this;
  ((void (*)(void))this->vfptr->BeginObject)();
  v6 = (UFG::qReflectField *)v4->mOrderedFields.mNode.mNext;
  v7 = 0i64;
  v26 = 0i64;
  v25 = (signed __int64)&v4->mOrderedFields;
  if ( v6 != (UFG::qReflectField *)&v4->mOrderedFields )
  {
    do
    {
      v8 = v6->mTypeName;
      v9 = UFG::ReflectionDB::Instance();
      v10 = -1i64;
      v11 = v9;
      if ( v8 )
      {
        v12 = *v8;
        if ( *v8 )
        {
          do
          {
            ++v8;
            v10 = (v10 >> 8) ^ sCrcTable64[(unsigned __int8)(v10 ^ v12)];
            v12 = *v8;
          }
          while ( *v8 );
          v3 = v28;
        }
      }
      v13 = (UFG::qReflectType *)v11->mTypes.mTree.mHead.mChildren[0];
      while ( v13 != (UFG::qReflectType *)&v11->mTypes )
      {
        if ( v13->mBaseNode.mUID >= v10 )
        {
          if ( v13->mBaseNode.mUID <= v10 )
            goto LABEL_13;
          v13 = (UFG::qReflectType *)v13->mBaseNode.mChildren[0];
        }
        else
        {
          v13 = (UFG::qReflectType *)v13->mBaseNode.mChildren[1];
        }
      }
      v13 = 0i64;
LABEL_13:
      v14 = &v3[v6->mByteOffset];
      v29 = v14;
      v5->vfptr->BeginField(v5, v6, v13, v14);
      v15 = v6->mByteOffset;
      if ( v15 > v26 )
      {
        v16 = v15 - v26;
        v5->vfptr->BeginPadding(v5, v15 - v26, &v28[v26]);
        v26 += v16;
      }
      v17 = v6->mFlags;
      if ( _bittest((const signed int *)&v17, 0xDu) )
      {
        if ( v5->vfptr->BeginPointerField(v5, v6, v13, v14) )
        {
          v23 = 0i64;
          if ( v6->mArrayLength )
          {
            do
            {
              v5->vfptr->BeginPointer(v5, v13, v14);
              v5->vfptr->BeginPointer(v5, v6, v13, v14);
              v5->vfptr->EndPointer(v5, v13, v14);
              v14 += 8;
              ++v23;
            }
            while ( v23 < v6->mArrayLength );
            v14 = v29;
          }
        }
        v26 += 8 * v6->mArrayLength;
      }
      else
      {
        if ( v17 & 0x20 )
        {
          if ( v5->vfptr->BeginArrayField(v5, v6, v13, v14) )
          {
            v18 = 0i64;
            v24 = 0i64;
            if ( v6->mArrayLength )
            {
              do
              {
                v19 = &v29[v18 * v13->mNumBytes];
                v5->vfptr->BeginArrayPointer(v5, v13, &v29[v18 * v13->mNumBytes]);
                UFG::qReflectVisitor::VisitObject(v5, v13, v19);
                v5->vfptr->EndArrayPointer(v5, v13, v19);
                v18 = v24 + 1;
                v24 = v18;
              }
              while ( v18 < v6->mArrayLength );
              v14 = v29;
            }
          }
        }
        else
        {
          v20 = (v17 & 1) == 0;
          v21 = v5->vfptr;
          if ( v20 )
          {
            if ( v21->BeginObjectField(v5, v6, v13, v14) )
            {
              v22 = 0i64;
              if ( v6->mArrayLength )
              {
                do
                  UFG::qReflectVisitor::VisitObject(v5, v13, &v29[v22++ * v13->mNumBytes]);
                while ( v22 < v6->mArrayLength );
              }
              v14 = v29;
              v5->vfptr->EndObjectField(v5, v6, v13, v29);
            }
          }
          else
          {
            v21->BeginBytes(v5, v6, v13, v14);
          }
        }
        v26 += v6->mArrayLength * v13->mNumBytes;
      }
      v5->vfptr->EndField(v5, v6, v13, v14);
      v6 = (UFG::qReflectField *)v6->mNext;
      v3 = v28;
    }
    while ( v6 != (UFG::qReflectField *)v25 );
    v7 = v26;
    v4 = v27;
  }
  if ( v4->mNumBytes > v7 )
    v5->vfptr->BeginPadding(v5, LODWORD(v4->mNumBytes) - v7, &v3[v7]);
  v5->vfptr->EndObject(v5, v4, v3);
}

