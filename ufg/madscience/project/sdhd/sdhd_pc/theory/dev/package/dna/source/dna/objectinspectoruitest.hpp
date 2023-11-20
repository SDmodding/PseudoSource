// File Line: 271
// RVA: 0x1B0000
void __fastcall UITest::HandleTest::HandleTest(UITest::HandleTest *this, MemImageLoadFlag f)
{
  UITest::HandleTest *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::HandleTest,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::HandleTest::`vftable';
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&this->mValueHandle);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mSubClassHandle);
  UFG::qReflectHandleBase::qReflectHandleBase((UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *)&v2->mGenericHandle);
}

// File Line: 290
// RVA: 0x1AFF50
void __fastcall UITest::HandleArrayTest::HandleArrayTest(UITest::HandleArrayTest *this, MemImageLoadFlag f)
{
  UITest::HandleArrayTest *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+60h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::HandleArrayTest,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::HandleArrayTest::`vftable';
  `eh vector constructor iterator'(
    this->mHandles,
    0x28ui64,
    5,
    (void (__fastcall *)(void *))UFG::qReflectHandle<UFG::qReflectObject>::qReflectHandle<UFG::qReflectObject>);
  v2->mHandleArray.mData.mFlags = 2;
}

// File Line: 317
// RVA: 0x1B00C0
void __fastcall UITest::SymbolTest::SymbolTest(UITest::SymbolTest *this, MemImageLoadFlag f)
{
  UITest::SymbolTest *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v5; // [rsp+50h] [rbp+18h]

  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mUID = 0i64;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v5 = &this->mHandles;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::SymbolTest,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::SymbolTest::`vftable';
  _((AMD_HD3D *)this->mWiseSymbol.mUID);
  v2->mSymbolArray.mData.mFlags = 2;
}

// File Line: 420
// RVA: 0x1B0150
void __fastcall UITest::UITestCase::UITestCase(UITest::UITestCase *this, MemImageLoadFlag f)
{
  UITest::UITestCase *v2; // rbx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v3; // rdx
  unsigned __int64 v4; // rax
  UITest::ColourTest *v5; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v6; // rcx
  unsigned __int64 v7; // rax
  UITest::ValueTest *v8; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v9; // rcx
  unsigned __int64 v10; // rax
  UITest::ValueSubClass *v11; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v12; // rcx
  unsigned __int64 v13; // rax
  UITest::PointerTest *v14; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v15; // rcx
  unsigned __int64 v16; // rax
  UITest::StringTest *v17; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v18; // rcx
  unsigned __int64 v19; // rax
  UITest::EnumValueTest *v20; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v21; // rcx
  unsigned __int64 v22; // rax
  UITest::ArrayTest *v23; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v24; // rcx
  unsigned __int64 v25; // rax
  UITest::ArrayPointerTest *v26; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v27; // rcx
  unsigned __int64 v28; // rax
  UITest::MathValueTest *v29; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v30; // rcx
  unsigned __int64 v31; // rax
  UITest::DefaultValues *v32; // rdx
  UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *v33; // rcx
  unsigned __int64 v34; // rax
  unsigned int fa; // [rsp+68h] [rbp+30h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v36; // [rsp+70h] [rbp+38h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v37; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v38; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v39; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v40; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v41; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v42; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v43; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v44; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v45; // [rsp+78h] [rbp+40h]
  UFG::qList<UFG::qReflectHandleBase,UFG::qReflectHandleBase,1,0> *v46; // [rsp+78h] [rbp+40h]

  fa = f.flag;
  v2 = this;
  v3 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mBaseNode;
  v4 = this->mBaseNode.mUID;
  v3->mBaseNode.mParent = &v3->mBaseNode;
  v3->mBaseNode.mChildren[0] = &v3->mBaseNode;
  v3->mBaseNode.mChildren[1] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[0] = &v3->mBaseNode;
  v3->mBaseNode.mNeighbours[1] = &v3->mBaseNode;
  v3->mBaseNode.mUID = v4;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v36 = &this->mHandles;
  v36->mNode.mPrev = &v36->mNode;
  v36->mNode.mNext = &v36->mNode;
  this->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::UITestCase,UFG::qReflectObject>::`vftable';
  this->vfptr = (UFG::qReflectObjectVtbl *)&UITest::UITestCase::`vftable';
  v5 = &this->mColours;
  v6 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&this->mColours.mBaseNode;
  v7 = v6->mBaseNode.mUID;
  v6->mBaseNode.mParent = &v6->mBaseNode;
  v6->mBaseNode.mChildren[0] = &v6->mBaseNode;
  v6->mBaseNode.mChildren[1] = &v6->mBaseNode;
  v6->mBaseNode.mNeighbours[0] = &v6->mBaseNode;
  v6->mBaseNode.mNeighbours[1] = &v6->mBaseNode;
  v6->mBaseNode.mUID = v7;
  v5->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v37 = &v5->mHandles;
  v37->mNode.mPrev = &v37->mNode;
  v37->mNode.mNext = &v37->mNode;
  v5->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ColourTest,UFG::qReflectObject>::`vftable';
  v5->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ColourTest::`vftable';
  v5->mColours.mData.mFlags = 2;
  v8 = &v2->mValueTest;
  v9 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mValueTest.mBaseNode;
  v10 = v2->mValueTest.mBaseNode.mUID;
  v9->mBaseNode.mParent = &v9->mBaseNode;
  v9->mBaseNode.mChildren[0] = &v9->mBaseNode;
  v9->mBaseNode.mChildren[1] = &v9->mBaseNode;
  v9->mBaseNode.mNeighbours[0] = &v9->mBaseNode;
  v9->mBaseNode.mNeighbours[1] = &v9->mBaseNode;
  v9->mBaseNode.mUID = v10;
  v2->mValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v38 = &v2->mValueTest.mHandles;
  v38->mNode.mPrev = &v38->mNode;
  v38->mNode.mNext = &v38->mNode;
  v8->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::`vftable';
  v8->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueTest::`vftable';
  v11 = &v2->mValueSubClassTest;
  v12 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mValueSubClassTest.mBaseNode;
  v13 = v2->mValueSubClassTest.mBaseNode.mUID;
  v12->mBaseNode.mParent = &v12->mBaseNode;
  v12->mBaseNode.mChildren[0] = &v12->mBaseNode;
  v12->mBaseNode.mChildren[1] = &v12->mBaseNode;
  v12->mBaseNode.mNeighbours[0] = &v12->mBaseNode;
  v12->mBaseNode.mNeighbours[1] = &v12->mBaseNode;
  v12->mBaseNode.mUID = v13;
  v2->mValueSubClassTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v39 = &v2->mValueSubClassTest.mHandles;
  v39->mNode.mPrev = &v39->mNode;
  v39->mNode.mNext = &v39->mNode;
  v11->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueTest,UFG::qReflectObject>::`vftable';
  v11->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueTest::`vftable';
  v11->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ValueSubClass,UITest::ValueTest>::`vftable';
  v11->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ValueSubClass::`vftable';
  v14 = &v2->mPointerTest;
  v15 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mPointerTest.mBaseNode;
  v16 = v2->mPointerTest.mBaseNode.mUID;
  v15->mBaseNode.mParent = &v15->mBaseNode;
  v15->mBaseNode.mChildren[0] = &v15->mBaseNode;
  v15->mBaseNode.mChildren[1] = &v15->mBaseNode;
  v15->mBaseNode.mNeighbours[0] = &v15->mBaseNode;
  v15->mBaseNode.mNeighbours[1] = &v15->mBaseNode;
  v15->mBaseNode.mUID = v16;
  v2->mPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v40 = &v2->mPointerTest.mHandles;
  v40->mNode.mPrev = &v40->mNode;
  v40->mNode.mNext = &v40->mNode;
  v14->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::PointerTest,UFG::qReflectObject>::`vftable';
  v14->vfptr = (UFG::qReflectObjectVtbl *)&UITest::PointerTest::`vftable';
  v17 = &v2->mStringTest;
  v18 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mStringTest.mBaseNode;
  v19 = v2->mStringTest.mBaseNode.mUID;
  v18->mBaseNode.mParent = &v18->mBaseNode;
  v18->mBaseNode.mChildren[0] = &v18->mBaseNode;
  v18->mBaseNode.mChildren[1] = &v18->mBaseNode;
  v18->mBaseNode.mNeighbours[0] = &v18->mBaseNode;
  v18->mBaseNode.mNeighbours[1] = &v18->mBaseNode;
  v18->mBaseNode.mUID = v19;
  v2->mStringTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v41 = &v2->mStringTest.mHandles;
  v41->mNode.mPrev = &v41->mNode;
  v41->mNode.mNext = &v41->mNode;
  v17->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::StringTest,UFG::qReflectObject>::`vftable';
  v17->vfptr = (UFG::qReflectObjectVtbl *)&UITest::StringTest::`vftable';
  v2->mStringTest.mString.mText.mData.mFlags = 2;
  v20 = &v2->mEnumValueTest;
  v21 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mEnumValueTest.mBaseNode;
  v22 = v2->mEnumValueTest.mBaseNode.mUID;
  v21->mBaseNode.mParent = &v21->mBaseNode;
  v21->mBaseNode.mChildren[0] = &v21->mBaseNode;
  v21->mBaseNode.mChildren[1] = &v21->mBaseNode;
  v21->mBaseNode.mNeighbours[0] = &v21->mBaseNode;
  v21->mBaseNode.mNeighbours[1] = &v21->mBaseNode;
  v21->mBaseNode.mUID = v22;
  v2->mEnumValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v42 = &v2->mEnumValueTest.mHandles;
  v42->mNode.mPrev = &v42->mNode;
  v42->mNode.mNext = &v42->mNode;
  v20->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::EnumValueTest,UFG::qReflectObject>::`vftable';
  v20->vfptr = (UFG::qReflectObjectVtbl *)&UITest::EnumValueTest::`vftable';
  v23 = &v2->mArrayTest;
  v24 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mArrayTest.mBaseNode;
  v25 = v2->mArrayTest.mBaseNode.mUID;
  v24->mBaseNode.mParent = &v24->mBaseNode;
  v24->mBaseNode.mChildren[0] = &v24->mBaseNode;
  v24->mBaseNode.mChildren[1] = &v24->mBaseNode;
  v24->mBaseNode.mNeighbours[0] = &v24->mBaseNode;
  v24->mBaseNode.mNeighbours[1] = &v24->mBaseNode;
  v24->mBaseNode.mUID = v25;
  v2->mArrayTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v43 = &v2->mArrayTest.mHandles;
  v43->mNode.mPrev = &v43->mNode;
  v43->mNode.mNext = &v43->mNode;
  v23->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ArrayTest,UFG::qReflectObject>::`vftable';
  v23->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ArrayTest::`vftable';
  v2->mArrayTest.mFloatValues.mData.mFlags = 2;
  v2->mArrayTest.mData.mData.mFlags = 2;
  v2->mArrayTest.mValues.mData.mFlags = 2;
  v2->mArrayTest.mMyStringArray.mData.mFlags = 2;
  v26 = &v2->mArrayPointerTest;
  v27 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mArrayPointerTest.mBaseNode;
  v28 = v2->mArrayPointerTest.mBaseNode.mUID;
  v27->mBaseNode.mParent = &v27->mBaseNode;
  v27->mBaseNode.mChildren[0] = &v27->mBaseNode;
  v27->mBaseNode.mChildren[1] = &v27->mBaseNode;
  v27->mBaseNode.mNeighbours[0] = &v27->mBaseNode;
  v27->mBaseNode.mNeighbours[1] = &v27->mBaseNode;
  v27->mBaseNode.mUID = v28;
  v2->mArrayPointerTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v44 = &v2->mArrayPointerTest.mHandles;
  v44->mNode.mPrev = &v44->mNode;
  v44->mNode.mNext = &v44->mNode;
  v26->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::ArrayPointerTest,UFG::qReflectObject>::`vftable';
  v26->vfptr = (UFG::qReflectObjectVtbl *)&UITest::ArrayPointerTest::`vftable';
  v2->mArrayPointerTest.mValues.mData.mFlags = 2;
  v29 = &v2->mMathValueTest;
  v30 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mMathValueTest.mBaseNode;
  v31 = v2->mMathValueTest.mBaseNode.mUID;
  v30->mBaseNode.mParent = &v30->mBaseNode;
  v30->mBaseNode.mChildren[0] = &v30->mBaseNode;
  v30->mBaseNode.mChildren[1] = &v30->mBaseNode;
  v30->mBaseNode.mNeighbours[0] = &v30->mBaseNode;
  v30->mBaseNode.mNeighbours[1] = &v30->mBaseNode;
  v30->mBaseNode.mUID = v31;
  v2->mMathValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v45 = &v2->mMathValueTest.mHandles;
  v45->mNode.mPrev = &v45->mNode;
  v45->mNode.mNext = &v45->mNode;
  v29->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::MathValueTest,UFG::qReflectObject>::`vftable';
  v29->vfptr = (UFG::qReflectObjectVtbl *)&UITest::MathValueTest::`vftable';
  UITest::HandleTest::HandleTest(&v2->mHandleTest, (MemImageLoadFlag)fa);
  UITest::HandleArrayTest::HandleArrayTest(&v2->mHandleArrayTest, (MemImageLoadFlag)fa);
  UITest::SymbolTest::SymbolTest(&v2->mSymbolTest, (MemImageLoadFlag)fa);
  v32 = &v2->mDefaultValueTest;
  v33 = (UFG::qTreeNode64<UFG::qReflectObject,UFG::qReflectObject> *)&v2->mDefaultValueTest.mBaseNode;
  v34 = v2->mDefaultValueTest.mBaseNode.mUID;
  v33->mBaseNode.mParent = &v33->mBaseNode;
  v33->mBaseNode.mChildren[0] = &v33->mBaseNode;
  v33->mBaseNode.mChildren[1] = &v33->mBaseNode;
  v33->mBaseNode.mNeighbours[0] = &v33->mBaseNode;
  v33->mBaseNode.mNeighbours[1] = &v33->mBaseNode;
  v33->mBaseNode.mUID = v34;
  v2->mDefaultValueTest.vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObject::`vftable';
  v46 = &v2->mDefaultValueTest.mHandles;
  v46->mNode.mPrev = &v46->mNode;
  v46->mNode.mNext = &v46->mNode;
  v32->vfptr = (UFG::qReflectObjectVtbl *)&UFG::qReflectObjectType<UITest::DefaultValues,UFG::qReflectObject>::`vftable';
  v32->vfptr = (UFG::qReflectObjectVtbl *)&UITest::DefaultValues::`vftable';
  v2->mDefaultValueTest.mString.mText.mData.mFlags = 2;
}

