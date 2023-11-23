// File Line: 20
// RVA: 0x17E7B0
void __fastcall UFG::qReflectVisitor::TrackObject(
        UFG::qReflectVisitor *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  unsigned __int64 v5; // rdi
  UFG::ReflectionDB *v6; // rax
  UFG::qReflectType *v7; // r8
  __int64 v8; // r9
  unsigned int size; // r10d
  UFG::qReflectVisitor::ObjectData *p; // r11
  __int64 v11; // r9
  unsigned int v12; // r11d
  UFG::qReflectVisitor::ArrayData *v13; // rdi
  unsigned __int64 v14; // rdx
  __int64 v15; // rdi
  unsigned int v16; // ebx
  unsigned int capacity; // edx
  unsigned int v18; // edx
  UFG::qReflectVisitor::ObjectData *v19; // rbx
  __int64 *v20; // rcx
  __int64 **v21; // rax
  UFG::qReflectType *v22; // [rsp+28h] [rbp-9h]
  const char *v23; // [rsp+30h] [rbp-1h]
  __int64 *v24; // [rsp+38h] [rbp+7h] BYREF
  __int64 **v25; // [rsp+40h] [rbp+Fh]
  int length[2]; // [rsp+48h] [rbp+17h]
  char *text; // [rsp+50h] [rbp+1Fh]
  __int64 v28; // [rsp+58h] [rbp+27h]
  unsigned __int64 v29; // [rsp+60h] [rbp+2Fh]
  unsigned __int64 v30; // [rsp+68h] [rbp+37h]
  __int64 **retaddr; // [rsp+A8h] [rbp+77h]

  if ( object_data && (reflection_type->mFlags & 0x10) != 0 )
  {
    v5 = *((_QWORD *)object_data + 7);
    v6 = UFG::ReflectionDB::Instance();
    v7 = (UFG::qReflectType *)v6->mTypes.mTree.mHead.mChildren[0];
    while ( v7 != (UFG::qReflectType *)&v6->mTypes )
    {
      if ( v7->mBaseNode.mUID >= v5 )
      {
        if ( v7->mBaseNode.mUID <= v5 )
          goto LABEL_10;
        v7 = (UFG::qReflectType *)v7->mBaseNode.mChildren[0];
      }
      else
      {
        v7 = (UFG::qReflectType *)v7->mBaseNode.mChildren[1];
      }
    }
    v7 = 0i64;
LABEL_10:
    v8 = 0i64;
    size = this->mTrackedObjects.size;
    if ( size )
    {
      p = this->mTrackedObjects.p;
      while ( object_data < p[v8].mObjectData || object_data >= &p[v8].mObjectData[p[v8].mReflectionType->mNumBytes] )
      {
        v8 = (unsigned int)(v8 + 1);
        if ( (unsigned int)v8 >= size )
          goto LABEL_15;
      }
    }
    else
    {
LABEL_15:
      v11 = 0i64;
      v12 = this->mArrays.size;
      if ( v12 )
      {
        v13 = this->mArrays.p;
        while ( 1 )
        {
          v14 = (unsigned __int64)*v13[v11].mArrayLocation;
          if ( (unsigned __int64)object_data >= v14
            && (unsigned __int64)object_data < v14 + v13[v11].mArraySize * v13[v11].mSubType->mNumBytes )
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
        v23 = object_data;
        v15 = this->mTrackedObjects.size;
        v16 = v15 + 1;
        capacity = this->mTrackedObjects.capacity;
        if ( (int)v15 + 1 > capacity )
        {
          if ( capacity )
            v18 = 2 * capacity;
          else
            v18 = 1;
          for ( ; v18 < v16; v18 *= 2 )
            ;
          if ( v18 - v16 > 0x10000 )
            v18 = v15 + 65537;
          UFG::qArray<UFG::qReflectVisitor::ObjectData,0>::Reallocate(&this->mTrackedObjects, v18, "qArray.Add");
          v7 = v22;
        }
        this->mTrackedObjects.size = v16;
        v19 = &this->mTrackedObjects.p[v15];
        v19->mReflectionType = v7;
        v19->mObjectData = v23;
        UFG::qString::Set(&v19->mName, text, length[1], 0i64, 0);
        v19->mObjectId = v29;
        v19->mNameId = v30;
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

// File Line: 68
// RVA: 0x17D090
void __fastcall UFG::qReflectVisitor::SetObjectName(UFG::qReflectVisitor *this, unsigned int index, UFG::qString *name)
{
  UFG::qString::Set(&this->mTrackedObjects.p[index].mName, name->mData, name->mLength, 0i64, 0);
}

// File Line: 73
// RVA: 0x166680
void __fastcall UFG::qReflectVisitor::AddPointerPatch(
        UFG::qReflectVisitor *this,
        UFG::qReflectType *object_type,
        UFG::qReflectField *field,
        unsigned int array_index,
        UFG::qReflectType *reflection_type,
        const char **pointer,
        const char *data)
{
  UFG::qArray<UFG::qReflectVisitor::PointerPatch,0> *p_mPatches; // rsi
  __int64 size; // rdi
  unsigned int v9; // r10d
  const char **p_mObject; // rax
  unsigned int capacity; // edx
  unsigned int v12; // ebx
  unsigned int v13; // edx
  UFG::qReflectVisitor::PointerPatch *p; // rax
  __int64 v15; // rcx
  __int128 v16; // [rsp+20h] [rbp-48h]
  __int128 v17; // [rsp+30h] [rbp-38h]
  __int128 v18; // [rsp+50h] [rbp-18h]

  if ( pointer && *pointer )
  {
    p_mPatches = &this->mPatches;
    size = this->mPatches.size;
    v9 = 0;
    if ( (_DWORD)size )
    {
      p_mObject = &this->mPatches.p->mObject;
      while ( pointer != (const char **)*(p_mObject - 1) || data != *p_mObject )
      {
        ++v9;
        p_mObject += 8;
        if ( v9 >= (unsigned int)size )
          goto LABEL_8;
      }
    }
    else
    {
LABEL_8:
      *(_QWORD *)&v16 = object_type;
      capacity = this->mPatches.capacity;
      *((_QWORD *)&v16 + 1) = field;
      v12 = size + 1;
      LODWORD(v17) = array_index;
      *((_QWORD *)&v17 + 1) = reflection_type;
      if ( (int)size + 1 > capacity )
      {
        if ( capacity )
          v13 = 2 * capacity;
        else
          v13 = 1;
        for ( ; v13 < v12; v13 *= 2 )
          ;
        if ( v13 - v12 > 0x10000 )
          v13 = size + 65537;
        UFG::qArray<UFG::qReflectVisitor::PointerPatch,0>::Reallocate(&this->mPatches, v13, "qArray.Add");
      }
      p = p_mPatches->p;
      p_mPatches->size = v12;
      v15 = size << 6;
      *(_OWORD *)((char *)&p->mObjectType + v15) = v16;
      *(_OWORD *)((char *)&p->mArrayIndex + v15) = v17;
      *(_OWORD *)((char *)&p->mPointer + v15) = __PAIR128__((unsigned __int64)data, (unsigned __int64)pointer);
      *(_OWORD *)((char *)&p->mPointerId + v15) = v18;
    }
  }
}

// File Line: 110
// RVA: 0x17F9C0
void __fastcall UFG::qReflectVisitor::VisitObjects(UFG::qReflectVisitor *this)
{
  UFG::ReflectionDB *v2; // rax
  const char *v3; // r10
  unsigned __int64 v4; // r9
  char v5; // cl
  __int64 v6; // r8
  UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *p_mTypes; // rdx
  UFG::qTree64Base::BaseNode *v8; // rax
  unsigned __int64 i; // rbx
  unsigned __int64 j; // rsi
  UFG::qReflectVisitor::ObjectData *v11; // rbx
  unsigned __int64 k; // r14
  UFG::qReflectVisitor::ArrayData *v13; // rbx
  __int64 m; // rsi
  UFG::qReflectField *mArrayField; // rdx
  unsigned int mFlags; // eax
  const char *v17; // rbp
  UFG::ReflectionDB *v18; // rax
  const char *v19; // r8
  unsigned __int64 v20; // r9
  char v21; // cl
  UFG::qReflectType *v22; // r8

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
  p_mTypes = &v2->mTypes;
  v8 = v2->mTypes.mTree.mHead.mChildren[0];
  while ( v8 != (UFG::qTree64Base::BaseNode *)p_mTypes )
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
  for ( i = 0i64; i < this->mTrackedObjects.size; ++i )
    UFG::qReflectVisitor::DiscoverObject(
      this,
      this->mTrackedObjects.p[(unsigned int)i].mReflectionType,
      this->mTrackedObjects.p[(unsigned int)i].mObjectData);
  ((void (__fastcall *)(UFG::qReflectVisitor *, UFG::qTree64<UFG::qReflectType,UFG::qReflectType,0> *, __int64, unsigned __int64))this->vfptr->BeginVisit)(
    this,
    p_mTypes,
    v6,
    v4);
  for ( j = 0i64; j < this->mTrackedObjects.size; ++j )
  {
    v11 = &this->mTrackedObjects.p[(unsigned int)j];
    this->vfptr->AlignTo(this, v11->mReflectionType->mAlignment);
    UFG::qReflectVisitor::VisitObject(this, v11->mReflectionType, v11->mObjectData);
  }
  for ( k = 0i64; k < this->mArrays.size; ++k )
  {
    v13 = &this->mArrays.p[(unsigned int)k];
    this->vfptr->AlignTo(this, v13->mSubType->mAlignment);
    if ( this->vfptr->BeginArray(this, v13) )
    {
      for ( m = 0i64; (unsigned int)m < v13->mArraySize; m = (unsigned int)(m + 1) )
      {
        mArrayField = v13->mArrayField;
        mFlags = mArrayField->mFlags;
        if ( (mFlags & 0x4000) != 0 )
        {
          v17 = &(*v13->mArrayLocation)[8 * m];
          this->vfptr->BeginPointer(this, v13->mSubType, v17);
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
          v22 = (UFG::qReflectType *)v18->mTypes.mTree.mHead.mChildren[0];
          while ( v22 != (UFG::qReflectType *)&v18->mTypes )
          {
            if ( v22->mBaseNode.mUID >= v20 )
            {
              if ( v22->mBaseNode.mUID <= v20 )
                goto LABEL_26;
              v22 = (UFG::qReflectType *)v22->mBaseNode.mChildren[0];
            }
            else
            {
              v22 = (UFG::qReflectType *)v22->mBaseNode.mChildren[1];
            }
          }
          v22 = 0i64;
LABEL_26:
          this->vfptr->BeginPointer(this, v13->mArrayField, v22, v17);
          this->vfptr->EndPointer(this, v13->mSubType, v17);
        }
        else if ( (mFlags & 1) != 0 )
        {
          this->vfptr->BeginBytes(
            this,
            mArrayField,
            v13->mSubType,
            &(*v13->mArrayLocation)[~(v13->mSubType->mAlignment - 1i64) & (v13->mSubType->mAlignment
                                                                         + (unsigned int)m * v13->mSubType->mNumBytes
                                                                         - 1)]);
        }
        else
        {
          UFG::qReflectVisitor::VisitObject(
            this,
            v13->mSubType,
            &(*v13->mArrayLocation)[~(v13->mSubType->mAlignment - 1i64) & (v13->mSubType->mAlignment
                                                                         + (unsigned int)m * v13->mSubType->mNumBytes
                                                                         - 1)]);
        }
      }
      this->vfptr->EndArray(this, v13);
    }
  }
  this->vfptr->EndVisit(this);
}

// File Line: 178
// RVA: 0x16C9B0
void __fastcall UFG::qReflectVisitor::DiscoverObject(
        UFG::qReflectVisitor *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *mNext; // rbp
  const char *v4; // rsi
  UFG::qReflectVisitor *v5; // rdi
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *v6; // rbx
  UFG::ReflectionDB *v7; // rax
  unsigned __int64 v8; // rdx
  UFG::ReflectionDB *v9; // r8
  char mPrev; // al
  UFG::qTree64Base::BaseNode *v11; // rbx
  int v12; // eax
  const char **pointer; // rsi
  UFG::qReflectField *v14; // rax
  unsigned __int64 v15; // rbp
  UFG::qReflectField *v16; // rsi
  UFG::ReflectionDB *v17; // rax
  UFG::qReflectType *Type; // rax
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
  const char *v29; // rsi
  bool v30; // cf
  UFG::qNode<UFG::qReflectField,UFG::qReflectField> *j; // rsi
  char *data; // [rsp+30h] [rbp-C8h]
  UFG::qReflectField *field; // [rsp+40h] [rbp-B8h]
  UFG::qReflectField *v34; // [rsp+48h] [rbp-B0h]
  char **v35; // [rsp+50h] [rbp-A8h]
  UFG::qTree64Base::BaseNode *i; // [rsp+58h] [rbp-A0h]
  char *v37; // [rsp+60h] [rbp-98h]
  __int64 v38; // [rsp+68h] [rbp-90h]
  __int64 v39; // [rsp+70h] [rbp-88h]
  UFG::qList<UFG::qReflectField,UFG::qReflectField,1,0> *p_mOrderedFields; // [rsp+78h] [rbp-80h]
  UFG::qReflectVisitor::ArrayData item; // [rsp+80h] [rbp-78h] BYREF
  unsigned int v45; // [rsp+118h] [rbp+20h]

  mNext = reflection_type->mOrderedFields.mNode.mNext;
  v4 = object_data;
  v5 = this;
  field = (UFG::qReflectField *)mNext;
  p_mOrderedFields = &reflection_type->mOrderedFields;
  if ( mNext != (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)&reflection_type->mOrderedFields )
  {
    while ( 1 )
    {
      v6 = mNext[4].mNext;
      v7 = UFG::ReflectionDB::Instance();
      v8 = -1i64;
      v9 = v7;
      if ( v6 )
      {
        mPrev = (char)v6->mPrev;
        if ( LOBYTE(v6->mPrev) )
        {
          do
          {
            v6 = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)((char *)v6 + 1);
            v8 = (v8 >> 8) ^ sCrcTable64[(unsigned __int8)(v8 ^ mPrev)];
            mPrev = (char)v6->mPrev;
          }
          while ( LOBYTE(v6->mPrev) );
          v4 = object_data;
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
      v35 = (char **)&v4[(unsigned __int64)mNext[6].mPrev];
      (*(void (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))&v5->vfptr->gap8[16])(
        v5,
        mNext,
        v11,
        v35);
      v12 = (int)mNext[7].mPrev;
      if ( (v12 & 0x40) != 0 )
        goto LABEL_39;
      if ( (v12 & 0x2000) != 0 )
      {
        pointer = (const char **)v35;
        if ( !(*(unsigned __int8 (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))&v5->vfptr->gap8[8])(
                v5,
                mNext,
                v11,
                v35) )
        {
LABEL_38:
          v4 = object_data;
          goto LABEL_39;
        }
        v14 = field;
        v15 = 0i64;
        if ( field->mArrayLength )
        {
          do
          {
            if ( (BYTE4(v11[1].mNeighbours[1]) & 0x10) != 0 )
            {
              UFG::qReflectVisitor::TrackObject(v5, (UFG::qReflectType *)v11, *pointer);
              UFG::qReflectVisitor::AddPointerPatch(
                v5,
                reflection_type,
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
          mNext = field;
          goto LABEL_38;
        }
LABEL_37:
        mNext = v14;
        goto LABEL_38;
      }
      if ( (v12 & 0x20) == 0 )
      {
        if ( (v12 & 1) != 0
          || !v5->vfptr->DiscoverObjectField(
                v5,
                (UFG::qReflectField *)mNext,
                (UFG::qReflectType *)v11,
                (const char *)v35) )
        {
          goto LABEL_39;
        }
        for ( j = 0i64; j < mNext[6].mNext; j = (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)((char *)j + 1) )
          UFG::qReflectVisitor::DiscoverObject(
            v5,
            (UFG::qReflectType *)v11,
            (const char *)v35 + (_QWORD)j * (__int64)v11[1].mNeighbours[0]);
        goto LABEL_38;
      }
      if ( (*(unsigned __int8 (__fastcall **)(UFG::qReflectVisitor *, UFG::qNode<UFG::qReflectField,UFG::qReflectField> *, UFG::qTree64Base::BaseNode *, char **))v5->vfptr->gap8)(
             v5,
             mNext,
             v11,
             v35) )
      {
        break;
      }
LABEL_39:
      v5->vfptr->EndDiscoverField(v5, (UFG::qReflectField *)mNext, (UFG::qReflectType *)v11, (const char *)v35);
      mNext = mNext->mNext;
      field = (UFG::qReflectField *)mNext;
      if ( mNext == (UFG::qNode<UFG::qReflectField,UFG::qReflectField> *)p_mOrderedFields )
        return;
    }
    v16 = (UFG::qReflectField *)v11[3].mChildren[1];
    v34 = v16;
    v17 = UFG::ReflectionDB::Instance();
    Type = UFG::ReflectionDB::GetType(v17, v16->mTypeName);
    v19 = 0i64;
    v20 = Type;
    v14 = field;
    v39 = 0i64;
    if ( !field->mArrayLength )
      goto LABEL_37;
    while ( 1 )
    {
      v21 = (char *)v35 + v19 * (__int64)v11[1].mNeighbours[0];
      v37 = v21;
      v22 = *((_DWORD *)v21 + 2);
      v45 = v22;
      if ( v22 )
      {
        item.mOwnerField = v14;
        item.mArrayData = *(const char **)v21;
        item.mArrayField = v34;
        item.mArraySize = v22;
        item.mArrayType = reflection_type;
        item.mArrayLocation = (const char **)v21;
        item.mSubType = v20;
        UFG::qArray<UFG::qReflectVisitor::ArrayData,0>::Add(&v5->mArrays, &item, "qArray.Add");
        v23 = v34;
        if ( (v34->mFlags & 1) == 0 )
        {
          v24 = 0;
          if ( v45 )
          {
            v25 = v45;
            v26 = 0i64;
            v38 = 0i64;
            while ( (v23->mFlags & 0x4000) != 0 )
            {
              if ( (v20->mFlags & 0x10) != 0 )
              {
                v27 = (const char **)(v26 + *(_QWORD *)v21);
                v28 = *v27;
                UFG::qReflectVisitor::TrackObject(this, v20, *v27);
                data = (char *)v28;
                v5 = this;
                UFG::qReflectVisitor::AddPointerPatch(this, reflection_type, v34, v24, v20, v27, data);
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
            v29 = (const char *)(*(_QWORD *)v37
                               + (~(v20->mAlignment - 1i64) & (v20->mAlignment + v24 * v20->mNumBytes - 1)));
            if ( v5->vfptr->DiscoverObjectField(v5, v23, v20, v29) )
              UFG::qReflectVisitor::DiscoverObject(v5, v20, v29);
            goto LABEL_33;
          }
LABEL_35:
          v11 = i;
        }
      }
      v30 = ++v39 < field->mArrayLength;
      v14 = field;
      v19 = v39;
      if ( !v30 )
        goto LABEL_37;
    }
  }
}bject(v5, v20, v29);
            goto LABEL_33;
          }
LABEL_35:
          v11 = i;
        }
      }
      v30 = ++v39 < field->mArrayLength;
      v14 = field;
      v19 = v39;
      if ( !v30 )
        got

// File Line: 278
// RVA: 0x17F690
void __fastcall UFG::qReflectVisitor::VisitObject(
        UFG::qReflectVisitor *this,
        UFG::qReflectType *reflection_type,
        const char *object_data)
{
  const char *v3; // rdi
  UFG::qReflectType *v4; // rbx
  UFG::qReflectField *mNext; // rbp
  unsigned __int64 v7; // rcx
  const char *mTypeName; // rbx
  UFG::ReflectionDB *v9; // rax
  unsigned __int64 v10; // rdx
  UFG::ReflectionDB *v11; // r8
  char v12; // al
  UFG::qReflectType *v13; // rbx
  const char *v14; // rdi
  unsigned __int64 mByteOffset; // rdx
  unsigned int mFlags; // eax
  unsigned __int64 v17; // rax
  const char *v18; // rdi
  bool v19; // zf
  UFG::qReflectVisitorVtbl *vfptr; // rax
  unsigned __int64 i; // rdi
  __int64 v22; // [rsp+20h] [rbp-48h]
  unsigned __int64 v23; // [rsp+20h] [rbp-48h]
  unsigned __int64 v24; // [rsp+20h] [rbp-48h]
  UFG::qReflectField *p_mOrderedFields; // [rsp+30h] [rbp-38h]
  unsigned __int64 v26; // [rsp+70h] [rbp+8h]
  const char *v29; // [rsp+88h] [rbp+20h]

  v3 = object_data;
  v4 = reflection_type;
  ((void (__fastcall *)(UFG::qReflectVisitor *))this->vfptr->BeginObject)(this);
  mNext = (UFG::qReflectField *)v4->mOrderedFields.mNode.mNext;
  v7 = 0i64;
  v26 = 0i64;
  p_mOrderedFields = (UFG::qReflectField *)&v4->mOrderedFields;
  if ( mNext != (UFG::qReflectField *)&v4->mOrderedFields )
  {
    do
    {
      mTypeName = mNext->mTypeName;
      v9 = UFG::ReflectionDB::Instance();
      v10 = -1i64;
      v11 = v9;
      if ( mTypeName )
      {
        v12 = *mTypeName;
        if ( *mTypeName )
        {
          do
          {
            ++mTypeName;
            v10 = (v10 >> 8) ^ sCrcTable64[(unsigned __int8)(v10 ^ v12)];
            v12 = *mTypeName;
          }
          while ( *mTypeName );
          v3 = object_data;
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
      v14 = &v3[mNext->mByteOffset];
      v29 = v14;
      this->vfptr->BeginField(this, mNext, v13, v14);
      mByteOffset = mNext->mByteOffset;
      if ( mByteOffset > v26 )
      {
        v22 = mByteOffset - v26;
        this->vfptr->BeginPadding(this, mByteOffset - v26, &object_data[v26]);
        v26 += v22;
      }
      mFlags = mNext->mFlags;
      if ( (mFlags & 0x2000) != 0 )
      {
        if ( this->vfptr->BeginPointerField(this, mNext, v13, v14) )
        {
          v23 = 0i64;
          if ( mNext->mArrayLength )
          {
            do
            {
              this->vfptr->BeginPointer(this, v13, v14);
              this->vfptr->BeginPointer(this, mNext, v13, v14);
              this->vfptr->EndPointer(this, v13, v14);
              v14 += 8;
              ++v23;
            }
            while ( v23 < mNext->mArrayLength );
            v14 = v29;
          }
        }
        v26 += 8 * mNext->mArrayLength;
      }
      else
      {
        if ( (mFlags & 0x20) != 0 )
        {
          if ( this->vfptr->BeginArrayField(this, mNext, v13, v14) )
          {
            v17 = 0i64;
            v24 = 0i64;
            if ( mNext->mArrayLength )
            {
              do
              {
                v18 = &v29[v17 * v13->mNumBytes];
                this->vfptr->BeginArrayPointer(this, v13, v18);
                UFG::qReflectVisitor::VisitObject(this, v13, v18);
                this->vfptr->EndArrayPointer(this, v13, v18);
                v17 = v24 + 1;
                v24 = v17;
              }
              while ( v17 < mNext->mArrayLength );
              v14 = v29;
            }
          }
        }
        else
        {
          v19 = (mFlags & 1) == 0;
          vfptr = this->vfptr;
          if ( v19 )
          {
            if ( vfptr->BeginObjectField(this, mNext, v13, v14) )
            {
              for ( i = 0i64; i < mNext->mArrayLength; ++i )
                UFG::qReflectVisitor::VisitObject(this, v13, &v29[i * v13->mNumBytes]);
              v14 = v29;
              this->vfptr->EndObjectField(this, mNext, v13, v29);
            }
          }
          else
          {
            vfptr->BeginBytes(this, mNext, v13, v14);
          }
        }
        v26 += mNext->mArrayLength * v13->mNumBytes;
      }
      this->vfptr->EndField(this, mNext, v13, v14);
      mNext = (UFG::qReflectField *)mNext->mNext;
      v3 = object_data;
    }
    while ( mNext != p_mOrderedFields );
    v7 = v26;
    v4 = reflection_type;
  }
  if ( v4->mNumBytes > v7 )
    this->vfptr->BeginPadding(this, LODWORD(v4->mNumBytes) - v7, &v3[v7]);
  this->vfptr->EndObject(this, v4, v3);
}

