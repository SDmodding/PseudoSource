// File Line: 840
// RVA: 0xA3F1E0
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxObject::FindProperty(fbxsdk_2014_1::FbxObject *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v4; // rbx

  v4 = result;
  fbxsdk_2014_1::FbxProperty::Find(&this->RootProperty, result, pName, pCaseSensitive);
  return v4;
}

// File Line: 851
// RVA: 0xA3F190
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxObject::FindProperty(fbxsdk_2014_1::FbxObject *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, fbxsdk_2014_1::FbxDataType *pDataType, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v5; // rbx

  v5 = result;
  fbxsdk_2014_1::FbxProperty::Find(&this->RootProperty, result, pName, pDataType, pCaseSensitive);
  return v5;
}

// File Line: 862
// RVA: 0xA3F220
fbxsdk_2014_1::FbxProperty *__fastcall fbxsdk_2014_1::FbxObject::FindPropertyHierarchical(fbxsdk_2014_1::FbxObject *this, fbxsdk_2014_1::FbxProperty *result, const char *pName, bool pCaseSensitive)
{
  fbxsdk_2014_1::FbxProperty *v4; // rbx

  v4 = result;
  fbxsdk_2014_1::FbxProperty::FindHierarchical(&this->RootProperty, result, pName, pCaseSensitive);
  return v4;
}

// File Line: 1659
// RVA: 0xA3EEC0
fbxsdk_2014_1::FbxFileTexture *__fastcall fbxsdk_2014_1::FbxCast<fbxsdk_2014_1::FbxFileTexture>(fbxsdk_2014_1::FbxObject *pObject)
{
  fbxsdk_2014_1::FbxFileTexture *v1; // rbx
  fbxsdk_2014_1::FbxClassId *v2; // rax
  fbxsdk_2014_1::FbxFileTexture *result; // rax
  char v4; // [rsp+30h] [rbp+8h]

  v1 = (fbxsdk_2014_1::FbxFileTexture *)pObject;
  if ( pObject
    && (v2 = (fbxsdk_2014_1::FbxClassId *)(*(__int64 (__fastcall **)(fbxsdk_2014_1::FbxObject *, char *))pObject->vfptr->gap8)(
                                            pObject,
                                            &v4),
        fbxsdk_2014_1::FbxClassId::Is(v2, &fbxsdk_2014_1::FbxFileTexture::ClassId)) )
  {
    result = v1;
  }
  else
  {
    result = 0i64;
  }
  return result;
}

