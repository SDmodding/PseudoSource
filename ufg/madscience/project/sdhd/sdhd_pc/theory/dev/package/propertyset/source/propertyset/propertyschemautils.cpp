// File Line: 26
// RVA: 0x1FF6A0
UFG::qString *__fastcall UFG::PropertySchemaUtils::classNameFromPropSetName(
        UFG::qString *result,
        const char *prop_set_name)
{
  UFG::qString text; // [rsp+30h] [rbp-38h] BYREF

  UFG::qString::qString(&text, prop_set_name);
  UFG::qString::ReplaceString(&text, "default-", &customCaption, 0);
  UFG::qString::ReplaceString(&text, "-", "_", 0);
  UFG::qString::qString(result, &text);
  UFG::qString::~qString(&text);
  return result;
}

// File Line: 49
// RVA: 0x1F39D0
void __fastcall UFG::PropertySchemaUtils::CopyPropertyValue(
        UFG::qPropertySet *srcPropSet,
        UFG::qPropertySet *dstPropSet,
        UFG::qArray<unsigned long,0> *propertyName)
{
  UFG::qVector3 *v3; // [rsp+28h] [rbp-C0h]
  UFG::qVector4 *v4; // [rsp+30h] [rbp-B8h]
  UFG::qMatrix44 *v5; // [rsp+38h] [rbp-B0h]
  int *v6; // [rsp+40h] [rbp-A8h]
  UFG::qTransQuat *v7; // [rsp+48h] [rbp-A0h]
  unsigned __int16 *v8; // [rsp+50h] [rbp-98h]
  bool *v9; // [rsp+58h] [rbp-90h]
  __int64 *v10; // [rsp+60h] [rbp-88h]
  char *v11; // [rsp+68h] [rbp-80h]
  float *v12; // [rsp+70h] [rbp-78h]
  UFG::qSymbol *v13; // [rsp+78h] [rbp-70h]
  char *v14; // [rsp+80h] [rbp-68h]
  UFG::qSymbolUC *v15; // [rsp+88h] [rbp-60h]
  char *v16; // [rsp+90h] [rbp-58h]
  UFG::qWiseSymbol *v17; // [rsp+98h] [rbp-50h]
  __int64 *v18; // [rsp+A0h] [rbp-48h]
  UFG::qPropertyList *v19; // [rsp+A8h] [rbp-40h]
  __int16 *v20; // [rsp+B0h] [rbp-38h]
  UFG::qPropertyList *v21; // [rsp+B8h] [rbp-30h]
  UFG::qVector2 *v; // [rsp+C0h] [rbp-28h]
  UFG::qPropertySet *v23; // [rsp+C8h] [rbp-20h]
  unsigned int *v24; // [rsp+D0h] [rbp-18h]
  UFG::qPropertySet *v25; // [rsp+D8h] [rbp-10h]

  switch ( UFG::qPropertySet::GetPropertyTypeFromName(srcPropSet, (UFG::qSymbol *)propertyName, DEPTH_RECURSE) )
  {
    case 0u:
      v14 = UFG::qPropertySet::Get<signed char>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<signed char>(dstPropSet, propertyName, *v14);
      break;
    case 1u:
      v20 = UFG::qPropertySet::Get<short>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<short>(dstPropSet, propertyName, *v20);
      break;
    case 2u:
      v6 = UFG::qPropertySet::Get<long>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<long>(dstPropSet, propertyName, *v6);
      break;
    case 3u:
      v10 = UFG::qPropertySet::Get<__int64>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<__int64>(dstPropSet, propertyName, *v10);
      break;
    case 5u:
      v16 = UFG::qPropertySet::Get<unsigned char>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned char>(dstPropSet, propertyName, *v16);
      break;
    case 6u:
      v8 = UFG::qPropertySet::Get<unsigned short>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned short>(dstPropSet, propertyName, *v8);
      break;
    case 7u:
      v24 = UFG::qPropertySet::Get<unsigned long>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned long>(dstPropSet, propertyName, *v24);
      break;
    case 8u:
      v18 = (__int64 *)UFG::qPropertySet::Get<unsigned __int64>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<unsigned __int64>(dstPropSet, propertyName, *v18);
      break;
    case 9u:
      v9 = UFG::qPropertySet::Get<bool>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<bool>(dstPropSet, propertyName, *v9);
      break;
    case 0xAu:
      v12 = UFG::qPropertySet::Get<float>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<float>(dstPropSet, propertyName, *v12);
      break;
    case 0xCu:
      v11 = UFG::qPropertySet::Get<char const *>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<char const *>(dstPropSet, propertyName, v11);
      break;
    case 0x11u:
      v = UFG::qPropertySet::Get<UFG::qVector2>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector2>(dstPropSet, propertyName, v);
      break;
    case 0x12u:
      v3 = UFG::qPropertySet::Get<UFG::qVector3>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector3>(dstPropSet, propertyName, v3);
      break;
    case 0x13u:
      v4 = UFG::qPropertySet::Get<UFG::qVector4>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qVector4>(dstPropSet, propertyName, v4);
      break;
    case 0x14u:
      v5 = UFG::qPropertySet::Get<UFG::qMatrix44>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qMatrix44>(dstPropSet, propertyName, v5);
      break;
    case 0x16u:
      v13 = UFG::qPropertySet::Get<UFG::qSymbol>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qSymbol>(dstPropSet, propertyName, v13);
      break;
    case 0x17u:
      v15 = UFG::qPropertySet::Get<UFG::qSymbolUC>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qSymbolUC>(dstPropSet, propertyName, v15);
      break;
    case 0x18u:
      v17 = UFG::qPropertySet::Get<UFG::qWiseSymbol>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qWiseSymbol>(dstPropSet, propertyName, v17);
      break;
    case 0x19u:
      v19 = UFG::qPropertySet::Get<UFG::qPropertyList>(srcPropSet, propertyName, DEPTH_LOCAL);
      v21 = (UFG::qPropertyList *)UFG::qPropertyList::Clone(v19);
      UFG::qPropertySet::Set<UFG::qPropertyList>(dstPropSet, propertyName, v21);
      break;
    case 0x1Au:
      v23 = UFG::qPropertySet::Get<UFG::qPropertySet>(srcPropSet, propertyName, DEPTH_LOCAL);
      v25 = UFG::qPropertySet::Clone(v23);
      UFG::qPropertySet::Set<UFG::qPropertySet>(dstPropSet, propertyName, v25);
      break;
    case 0x1Cu:
      v7 = UFG::qPropertySet::Get<UFG::qTransQuat>(srcPropSet, propertyName, DEPTH_RECURSE);
      UFG::qPropertySet::Set<UFG::qTransQuat>(dstPropSet, propertyName, v7);
      break;
    default:
      return;
  }
}

// File Line: 118
// RVA: 0x146BE20
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__gOutputSchemaClasses__()
{
  UFG::PropertySchemaUtils::gOutputSchemaClasses.mNode.mPrev = (UFG::qNode<UFG::PropertySchemaUtils::OutputSchemaClass,UFG::PropertySchemaUtils::OutputSchemaClass> *)&UFG::PropertySchemaUtils::gOutputSchemaClasses;
  UFG::PropertySchemaUtils::gOutputSchemaClasses.mNode.mNext = (UFG::qNode<UFG::PropertySchemaUtils::OutputSchemaClass,UFG::PropertySchemaUtils::OutputSchemaClass> *)&UFG::PropertySchemaUtils::gOutputSchemaClasses;
  return atexit((int (__fastcall *)())UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__gOutputSchemaClasses__);
}

// File Line: 555
// RVA: 0x146BF80
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassListSchema__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassListSchema, "default-schema-classlist");
  return atexit((int (__fastcall *)())UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassListSchema__);
}

// File Line: 556
// RVA: 0x146BFB0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassTypeList__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassTypeList, "ClassTypeList");
  return atexit((int (__fastcall *)())UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassTypeList__);
}

// File Line: 557
// RVA: 0x146BFE0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__symClassTypeMask__()
{
  UFG::qStaticSymbol::qStaticSymbol(&UFG::PropertySchemaUtils::symClassTypeMask, "ClassTypeMask");
  return atexit((int (__fastcall *)())UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__symClassTypeMask__);
}

// File Line: 559
// RVA: 0x146BDE0
__int64 UFG::PropertySchemaUtils::_dynamic_initializer_for__gClassTypes__()
{
  UFG::PropertySchemaUtils::gClassTypes.p = 0i64;
  UFG::PropertySchemaUtils::gClassTypes.size = 0;
  UFG::PropertySchemaUtils::gClassTypes.capacity = 0;
  return atexit((int (__fastcall *)())UFG::PropertySchemaUtils::_dynamic_atexit_destructor_for__gClassTypes__);
}

