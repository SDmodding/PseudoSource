// File Line: 35
// RVA: 0x15884E0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_0_unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E070 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,0,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorGet;
  return result;
}

// File Line: 36
// RVA: 0x158F590
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_1_Scaleform::GFx::AS3::Value_const__unsigned_long_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E080 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,1,Scaleform::GFx::AS3::Value const,unsigned long>::Method = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorSet;
  return result;
}

// File Line: 37
// RVA: 0x158F5C0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc1_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_2_Scaleform::GFx::AS3::Value_const__Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_____ptr64_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E090 = v1;
  Scaleform::GFx::AS3::ThunkFunc1<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,2,Scaleform::GFx::AS3::Value const,Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *>::Method = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::concat;
  return result;
}

// File Line: 38
// RVA: 0x15884B0
__int64 dynamic_initializer_for__Scaleform::GFx::AS3::ThunkFunc0_Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform_3_Scaleform::GFx::ASString_::Method__()
{
  __int64 result; // rax
  __int64 v1; // [rsp+8h] [rbp-10h]

  LODWORD(v1) = 0;
  result = v1;
  qword_14243E0A0 = v1;
  Scaleform::GFx::AS3::ThunkFunc0<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform,3,Scaleform::GFx::ASString>::Method = Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::toString;
  return result;
}

// File Line: 54
// RVA: 0x77C1F0
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::ColorTransform(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v2; // rbx

  v2 = this;
  Scaleform::GFx::AS3::Instance::Instance((Scaleform::GFx::AS3::Instance *)&this->vfptr, t);
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl::Object::`vftable;
  v2->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::`vftable;
  v2->redMultiplier = 1.0;
  v2->greenMultiplier = 1.0;
  v2->blueMultiplier = 1.0;
  v2->alphaMultiplier = 1.0;
  v2->redOffset = 0.0;
  v2->greenOffset = 0.0;
  v2->blueOffset = 0.0;
  v2->alphaOffset = 0.0;
}

// File Line: 62
// RVA: 0x830DC0
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorGet(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, unsigned int *result)
{
  *result = (unsigned __int8)(signed int)this->blueOffset | (((unsigned __int8)(signed int)this->greenOffset | ((unsigned __int8)(signed int)this->redOffset << 8)) << 8);
}

// File Line: 72
// RVA: 0x830E20
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::colorSet(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, Scaleform::GFx::AS3::Value *result, unsigned int value)
{
  this->blueMultiplier = 0.0;
  this->greenMultiplier = 0.0;
  this->redMultiplier = 0.0;
  this->redOffset = (float)BYTE2(value);
  this->greenOffset = (float)BYTE1(value);
  this->blueOffset = (float)(unsigned __int8)value;
}

// File Line: 94
// RVA: 0x831660
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::concat(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *second)
{
  double v3; // xmm4_8
  double v4; // xmm3_8
  double v5; // xmm2_8
  double v6; // xmm1_8

  v3 = this->redMultiplier;
  v4 = this->blueMultiplier;
  v5 = this->greenMultiplier;
  v6 = this->alphaMultiplier;
  this->redOffset = this->redMultiplier * second->redOffset + this->redOffset;
  this->blueOffset = v4 * second->blueOffset + this->blueOffset;
  this->greenOffset = v5 * second->greenOffset + this->greenOffset;
  this->alphaOffset = v6 * second->alphaOffset + this->alphaOffset;
  this->redMultiplier = v3 * second->redMultiplier;
  this->greenMultiplier = v5 * second->greenMultiplier;
  this->blueMultiplier = v4 * second->blueMultiplier;
  this->alphaMultiplier = v6 * second->alphaMultiplier;
}

// File Line: 110
// RVA: 0x861B00
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::toString(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v2; // rbx
  long double v3; // xmm0_8
  long double v4; // xmm0_8
  long double v5; // xmm0_8
  long double v6; // xmm0_8
  long double v7; // xmm0_8
  long double v8; // xmm0_8
  Scaleform::GFx::ASString *v9; // r13
  Scaleform::GFx::ASString *v10; // r12
  Scaleform::GFx::ASString *v11; // r15
  long double v12; // xmm0_8
  Scaleform::GFx::ASString *v13; // r14
  Scaleform::GFx::ASString *v14; // rsi
  Scaleform::GFx::ASString *v15; // rdi
  long double v16; // xmm0_8
  Scaleform::GFx::ASString *v17; // rbx
  Scaleform::GFx::ASString *v18; // rax
  Scaleform::GFx::ASString *v19; // rax
  Scaleform::GFx::ASString *v20; // rax
  Scaleform::GFx::ASString *v21; // rax
  Scaleform::GFx::ASString *v22; // rax
  Scaleform::GFx::ASString *v23; // rax
  Scaleform::GFx::ASString *v24; // rax
  Scaleform::GFx::ASString *v25; // rax
  Scaleform::GFx::ASString *v26; // rax
  Scaleform::GFx::ASString *v27; // rax
  Scaleform::GFx::ASString *v28; // rax
  Scaleform::GFx::ASString *v29; // rax
  Scaleform::GFx::ASString *v30; // rax
  Scaleform::GFx::ASString *v31; // rax
  Scaleform::GFx::ASString *v32; // rax
  Scaleform::GFx::ASString *v33; // rax
  Scaleform::GFx::ASString *v34; // rax
  Scaleform::GFx::ASString *v35; // rax
  Scaleform::GFx::ASString *v36; // rax
  Scaleform::GFx::ASString *v37; // rax
  Scaleform::GFx::ASString *v38; // rax
  Scaleform::GFx::ASString *v39; // rax
  Scaleform::GFx::ASString *v40; // rax
  Scaleform::GFx::ASString *v41; // rax
  Scaleform::GFx::ASStringNode *v42; // rcx
  bool v43; // zf
  Scaleform::GFx::ASStringNode *v44; // rcx
  Scaleform::GFx::ASStringNode *v45; // rcx
  Scaleform::GFx::ASStringNode *v46; // rcx
  Scaleform::GFx::ASStringNode *v47; // rcx
  Scaleform::GFx::ASStringNode *v48; // rcx
  Scaleform::GFx::ASStringNode *v49; // rcx
  Scaleform::GFx::ASStringNode *v50; // rcx
  Scaleform::GFx::ASStringNode *v51; // rcx
  Scaleform::GFx::ASStringNode *v52; // rcx
  Scaleform::GFx::ASStringNode *v53; // rcx
  Scaleform::GFx::ASStringNode *v54; // rcx
  Scaleform::GFx::ASStringNode *v55; // rcx
  Scaleform::GFx::ASStringNode *v56; // rcx
  Scaleform::GFx::ASStringNode *v57; // rcx
  Scaleform::GFx::ASStringNode *v58; // rcx
  Scaleform::GFx::ASStringNode *v59; // rcx
  Scaleform::GFx::ASStringNode *v60; // rcx
  Scaleform::GFx::ASStringNode *v61; // rcx
  Scaleform::GFx::ASStringNode *v62; // rcx
  Scaleform::GFx::ASStringNode *v63; // rcx
  Scaleform::GFx::ASStringNode *v64; // rcx
  Scaleform::GFx::ASStringNode *v65; // rcx
  Scaleform::GFx::ASStringNode *v66; // rcx
  Scaleform::GFx::ASStringNode *v67; // rcx
  unsigned int v68; // ebx
  Scaleform::GFx::ASStringNode *v69; // rcx
  Scaleform::GFx::ASStringNode *v70; // rcx
  Scaleform::GFx::ASStringNode *v71; // rcx
  unsigned int v72; // ebx
  Scaleform::GFx::ASStringNode *v73; // rcx
  Scaleform::GFx::ASStringNode *v74; // rcx
  Scaleform::GFx::ASStringNode *v75; // rcx
  unsigned int v76; // ebx
  Scaleform::GFx::ASStringNode *v77; // rcx
  Scaleform::GFx::ASStringNode *v78; // rcx
  Scaleform::GFx::ASStringNode *v79; // rcx
  unsigned int v80; // ebx
  Scaleform::GFx::ASStringNode *v81; // rcx
  Scaleform::GFx::ASStringNode *v82; // rcx
  Scaleform::GFx::ASStringNode *v83; // rcx
  unsigned int v84; // ebx
  Scaleform::GFx::ASStringNode *v85; // rcx
  Scaleform::GFx::ASStringNode *v86; // rcx
  Scaleform::GFx::ASStringNode *v87; // rcx
  unsigned int v88; // ebx
  Scaleform::GFx::ASStringNode *v89; // rcx
  Scaleform::GFx::ASStringNode *v90; // rcx
  Scaleform::GFx::ASStringNode *v91; // rcx
  unsigned int v92; // ebx
  Scaleform::GFx::ASStringNode *v93; // rcx
  Scaleform::GFx::ASStringNode *v94; // rcx
  Scaleform::GFx::ASStringNode *v95; // rcx
  unsigned int v96; // ebx
  Scaleform::GFx::ASStringNode *v97; // rcx
  Scaleform::GFx::AS3::Value v98; // [rsp+20h] [rbp-E0h]
  Scaleform::GFx::AS3::Value v99; // [rsp+40h] [rbp-C0h]
  Scaleform::GFx::AS3::Value v100; // [rsp+60h] [rbp-A0h]
  Scaleform::GFx::AS3::Value v101; // [rsp+80h] [rbp-80h]
  Scaleform::GFx::AS3::Value value; // [rsp+A0h] [rbp-60h]
  Scaleform::GFx::AS3::Value v103; // [rsp+C0h] [rbp-40h]
  Scaleform::GFx::AS3::Value v104; // [rsp+E0h] [rbp-20h]
  Scaleform::GFx::AS3::Value v105; // [rsp+100h] [rbp+0h]
  Scaleform::GFx::ASString v106; // [rsp+120h] [rbp+20h]
  Scaleform::GFx::ASString v107; // [rsp+128h] [rbp+28h]
  Scaleform::GFx::ASString *v108; // [rsp+130h] [rbp+30h]
  Scaleform::GFx::ASString v109; // [rsp+138h] [rbp+38h]
  Scaleform::GFx::ASString *v110; // [rsp+140h] [rbp+40h]
  Scaleform::GFx::ASString v111; // [rsp+148h] [rbp+48h]
  Scaleform::GFx::ASString *v112; // [rsp+150h] [rbp+50h]
  Scaleform::GFx::ASString v113; // [rsp+158h] [rbp+58h]
  Scaleform::GFx::ASString v114; // [rsp+160h] [rbp+60h]
  Scaleform::GFx::ASString v115; // [rsp+168h] [rbp+68h]
  Scaleform::GFx::ASString v116; // [rsp+170h] [rbp+70h]
  Scaleform::GFx::ASString v117; // [rsp+178h] [rbp+78h]
  Scaleform::GFx::ASString v118; // [rsp+180h] [rbp+80h]
  Scaleform::GFx::ASString v119; // [rsp+188h] [rbp+88h]
  Scaleform::GFx::ASString v120; // [rsp+190h] [rbp+90h]
  Scaleform::GFx::ASString v121; // [rsp+198h] [rbp+98h]
  Scaleform::GFx::ASString v122; // [rsp+1A0h] [rbp+A0h]
  Scaleform::GFx::ASString v123; // [rsp+1A8h] [rbp+A8h]
  Scaleform::GFx::ASString v124; // [rsp+1B0h] [rbp+B0h]
  Scaleform::GFx::ASString v125; // [rsp+1B8h] [rbp+B8h]
  Scaleform::GFx::ASString v126; // [rsp+1C0h] [rbp+C0h]
  Scaleform::GFx::ASString v127; // [rsp+1C8h] [rbp+C8h]
  Scaleform::GFx::ASString v128; // [rsp+1D0h] [rbp+D0h]
  Scaleform::GFx::ASString v129; // [rsp+1D8h] [rbp+D8h]
  Scaleform::GFx::ASString v130; // [rsp+1E0h] [rbp+E0h]
  Scaleform::GFx::ASString v131; // [rsp+1E8h] [rbp+E8h]
  Scaleform::GFx::ASString v132; // [rsp+1F0h] [rbp+F0h]
  Scaleform::GFx::ASString v133; // [rsp+1F8h] [rbp+F8h]
  Scaleform::GFx::ASString v134; // [rsp+200h] [rbp+100h]
  Scaleform::GFx::ASString v135; // [rsp+208h] [rbp+108h]
  Scaleform::GFx::ASString v136; // [rsp+210h] [rbp+110h]
  Scaleform::GFx::ASString v137; // [rsp+218h] [rbp+118h]
  Scaleform::GFx::ASString *v138; // [rsp+220h] [rbp+120h]
  Scaleform::GFx::ASString v139; // [rsp+228h] [rbp+128h]
  Scaleform::GFx::ASString v140; // [rsp+230h] [rbp+130h]
  Scaleform::GFx::ASString v141; // [rsp+238h] [rbp+138h]
  Scaleform::GFx::ASString v142; // [rsp+240h] [rbp+140h]
  Scaleform::GFx::ASString v143; // [rsp+248h] [rbp+148h]
  Scaleform::GFx::ASString v144; // [rsp+250h] [rbp+150h]
  Scaleform::GFx::ASString v145; // [rsp+258h] [rbp+158h]
  Scaleform::GFx::ASString v146; // [rsp+260h] [rbp+160h]
  Scaleform::GFx::ASString v147; // [rsp+268h] [rbp+168h]
  Scaleform::GFx::ASString v148; // [rsp+270h] [rbp+170h]
  Scaleform::GFx::ASString resulta; // [rsp+278h] [rbp+178h]
  Scaleform::GFx::ASString *v150; // [rsp+280h] [rbp+180h]
  Scaleform::GFx::ASString v151; // [rsp+288h] [rbp+188h]
  Scaleform::GFx::ASString v152; // [rsp+290h] [rbp+190h]
  Scaleform::GFx::ASString *v153; // [rsp+298h] [rbp+198h]
  Scaleform::GFx::ASString *v154; // [rsp+2A0h] [rbp+1A0h]
  Scaleform::GFx::ASString v155; // [rsp+2A8h] [rbp+1A8h]
  Scaleform::GFx::ASString *v156; // [rsp+2B0h] [rbp+1B0h]
  Scaleform::GFx::ASString v157; // [rsp+2B8h] [rbp+1B8h]
  Scaleform::GFx::ASString *v158; // [rsp+2C0h] [rbp+1C0h]
  Scaleform::GFx::ASString *v159; // [rsp+2C8h] [rbp+1C8h]
  Scaleform::GFx::ASString *v160; // [rsp+2D0h] [rbp+1D0h]
  Scaleform::GFx::ASString v161; // [rsp+2D8h] [rbp+1D8h]
  Scaleform::GFx::ASString *v162; // [rsp+2E0h] [rbp+1E0h]
  Scaleform::GFx::ASString v163; // [rsp+2E8h] [rbp+1E8h]
  Scaleform::GFx::ASString *v164; // [rsp+2F0h] [rbp+1F0h]
  Scaleform::GFx::ASString v165; // [rsp+2F8h] [rbp+1F8h]
  Scaleform::GFx::ASString *v166; // [rsp+300h] [rbp+200h]
  __int64 v167; // [rsp+308h] [rbp+208h]
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v168; // [rsp+360h] [rbp+260h]
  Scaleform::GFx::ASString *v169; // [rsp+368h] [rbp+268h]
  Scaleform::GFx::ASString *str; // [rsp+370h] [rbp+270h]
  Scaleform::GFx::ASString *v171; // [rsp+378h] [rbp+278h]

  v169 = result;
  v168 = this;
  v167 = -2i64;
  v2 = this;
  v112 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)this->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &resulta,
           ")");
  v3 = v2->alphaOffset;
  value.Flags = 4;
  value.Bonus.pWeakProxy = 0i64;
  value.value.VNumber = v3;
  v153 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v147, &value);
  v110 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v145,
           "alphaOffset=");
  v138 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v143,
           ", ");
  v4 = v2->blueOffset;
  v105.Flags = 4;
  v105.Bonus.pWeakProxy = 0i64;
  v105.value.VNumber = v4;
  v108 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v141, &v105);
  v159 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v139,
           "blueOffset=");
  v166 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v137,
           ", ");
  v5 = v2->greenOffset;
  v103.Flags = 4;
  v103.Bonus.pWeakProxy = 0i64;
  v103.value.VNumber = v5;
  v164 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v135, &v103);
  v162 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v133,
           "greenOffset=");
  v160 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v131,
           ", ");
  v6 = v2->redOffset;
  v101.Flags = 4;
  v101.Bonus.pWeakProxy = 0i64;
  v101.value.VNumber = v6;
  v158 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v129, &v101);
  v156 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v127,
           "redOffset=");
  v154 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v125,
           ", ");
  v7 = v2->alphaMultiplier;
  v99.Flags = 4;
  v99.Bonus.pWeakProxy = 0i64;
  v99.value.VNumber = v7;
  v150 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v123, &v99);
  v171 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
           (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
           &v121,
           "alphaMultiplier=");
  str = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v119,
          ", ");
  v8 = v2->blueMultiplier;
  v98.Flags = 4;
  v98.Bonus.pWeakProxy = 0i64;
  v98.value.VNumber = v8;
  v9 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v117, &v98);
  v10 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v115,
          "blueMultiplier=");
  v11 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v113,
          ", ");
  v12 = v2->greenMultiplier;
  v104.Flags = 4;
  v104.Bonus.pWeakProxy = 0i64;
  v104.value.VNumber = v12;
  v13 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v111, &v104);
  v14 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v109,
          "greenMultiplier=");
  v15 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v2->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v107,
          ", ");
  v16 = v2->redMultiplier;
  v100.Flags = 4;
  v100.Bonus.pWeakProxy = 0i64;
  v100.value.VNumber = v16;
  v17 = Scaleform::GFx::AS3::VM::AsString(v2->pTraits.pObject->pVM, &v152, &v100);
  v18 = Scaleform::GFx::ASStringBuiltinManagerT<enum  Scaleform::GFx::AS3::BuiltinType,64>::CreateConstString(
          (Scaleform::GFx::ASStringBuiltinManagerT<enum Scaleform::GFx::AS3::BuiltinType,64> *)v168->pTraits.pObject->pVM->StringManagerRef->Builtins,
          &v136,
          "(redMultiplier=");
  v19 = Scaleform::GFx::ASString::operator+(v18, &v151, v17);
  v20 = Scaleform::GFx::ASString::operator+(v19, &v134, v15);
  v21 = Scaleform::GFx::ASString::operator+(v20, &v106, v14);
  v22 = Scaleform::GFx::ASString::operator+(v21, &v132, v13);
  v23 = Scaleform::GFx::ASString::operator+(v22, &v165, v11);
  v24 = Scaleform::GFx::ASString::operator+(v23, &v130, v10);
  v25 = Scaleform::GFx::ASString::operator+(v24, &v148, v9);
  v26 = Scaleform::GFx::ASString::operator+(v25, &v128, str);
  v27 = Scaleform::GFx::ASString::operator+(v26, &v157, v171);
  v28 = Scaleform::GFx::ASString::operator+(v27, &v126, v150);
  v29 = Scaleform::GFx::ASString::operator+(v28, &v146, v154);
  v30 = Scaleform::GFx::ASString::operator+(v29, &v124, v156);
  v31 = Scaleform::GFx::ASString::operator+(v30, &v161, v158);
  v32 = Scaleform::GFx::ASString::operator+(v31, &v122, v160);
  v33 = Scaleform::GFx::ASString::operator+(v32, &v144, v162);
  v34 = Scaleform::GFx::ASString::operator+(v33, &v120, v164);
  v35 = Scaleform::GFx::ASString::operator+(v34, &v155, v166);
  v36 = Scaleform::GFx::ASString::operator+(v35, &v118, v159);
  v37 = Scaleform::GFx::ASString::operator+(v36, &v142, v108);
  v38 = Scaleform::GFx::ASString::operator+(v37, &v116, v138);
  v39 = Scaleform::GFx::ASString::operator+(v38, &v163, v110);
  v40 = Scaleform::GFx::ASString::operator+(v39, &v114, v153);
  v41 = Scaleform::GFx::ASString::operator+(v40, &v140, v112);
  Scaleform::GFx::ASString::Append(v169, v41);
  v42 = v140.pNode;
  v43 = v140.pNode->RefCount == 1;
  --v42->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v42);
  v44 = v114.pNode;
  v43 = v114.pNode->RefCount == 1;
  --v44->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v44);
  v45 = v163.pNode;
  v43 = v163.pNode->RefCount == 1;
  --v45->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v45);
  v46 = v116.pNode;
  v43 = v116.pNode->RefCount == 1;
  --v46->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v46);
  v47 = v142.pNode;
  v43 = v142.pNode->RefCount == 1;
  --v47->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v47);
  v48 = v118.pNode;
  v43 = v118.pNode->RefCount == 1;
  --v48->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v48);
  v49 = v155.pNode;
  v43 = v155.pNode->RefCount == 1;
  --v49->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v49);
  v50 = v120.pNode;
  v43 = v120.pNode->RefCount == 1;
  --v50->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v50);
  v51 = v144.pNode;
  v43 = v144.pNode->RefCount == 1;
  --v51->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v51);
  v52 = v122.pNode;
  v43 = v122.pNode->RefCount == 1;
  --v52->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v52);
  v53 = v161.pNode;
  v43 = v161.pNode->RefCount == 1;
  --v53->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v53);
  v54 = v124.pNode;
  v43 = v124.pNode->RefCount == 1;
  --v54->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v54);
  v55 = v146.pNode;
  v43 = v146.pNode->RefCount == 1;
  --v55->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v55);
  v56 = v126.pNode;
  v43 = v126.pNode->RefCount == 1;
  --v56->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v56);
  v57 = v157.pNode;
  v43 = v157.pNode->RefCount == 1;
  --v57->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v57);
  v58 = v128.pNode;
  v43 = v128.pNode->RefCount == 1;
  --v58->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v58);
  v59 = v148.pNode;
  v43 = v148.pNode->RefCount == 1;
  --v59->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v59);
  v60 = v130.pNode;
  v43 = v130.pNode->RefCount == 1;
  --v60->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v60);
  v61 = v165.pNode;
  v43 = v165.pNode->RefCount == 1;
  --v61->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v61);
  v62 = v132.pNode;
  v43 = v132.pNode->RefCount == 1;
  --v62->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v62);
  v63 = v106.pNode;
  v43 = v106.pNode->RefCount == 1;
  --v63->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v63);
  v64 = v134.pNode;
  v43 = v134.pNode->RefCount == 1;
  --v64->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v64);
  v65 = v151.pNode;
  v43 = v151.pNode->RefCount == 1;
  --v65->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v65);
  v66 = v136.pNode;
  v43 = v136.pNode->RefCount == 1;
  --v66->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v66);
  v67 = v152.pNode;
  v43 = v152.pNode->RefCount == 1;
  --v67->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v67);
  v68 = v100.Flags;
  if ( (v100.Flags & 0x1F) > 9 )
  {
    if ( (v100.Flags >> 9) & 1 )
    {
      v43 = v100.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v100.Bonus.pWeakProxy = 0i64;
      v100.value = 0ui64;
      v100.Flags = v68 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v100);
    }
  }
  v69 = v107.pNode;
  v43 = v107.pNode->RefCount == 1;
  --v69->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v69);
  v70 = v109.pNode;
  v43 = v109.pNode->RefCount == 1;
  --v70->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v70);
  v71 = v111.pNode;
  v43 = v111.pNode->RefCount == 1;
  --v71->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v71);
  v72 = v104.Flags;
  if ( (v104.Flags & 0x1F) > 9 )
  {
    if ( (v104.Flags >> 9) & 1 )
    {
      v43 = v104.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v104.Bonus.pWeakProxy = 0i64;
      v104.value = 0ui64;
      v104.Flags = v72 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v104);
    }
  }
  v73 = v113.pNode;
  v43 = v113.pNode->RefCount == 1;
  --v73->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v73);
  v74 = v115.pNode;
  v43 = v115.pNode->RefCount == 1;
  --v74->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v74);
  v75 = v117.pNode;
  v43 = v117.pNode->RefCount == 1;
  --v75->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v75);
  v76 = v98.Flags;
  if ( (v98.Flags & 0x1F) > 9 )
  {
    if ( (v98.Flags >> 9) & 1 )
    {
      v43 = v98.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v98.Bonus.pWeakProxy = 0i64;
      v98.value = 0ui64;
      v98.Flags = v76 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v98);
    }
  }
  v77 = v119.pNode;
  v43 = v119.pNode->RefCount == 1;
  --v77->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v77);
  v78 = v121.pNode;
  v43 = v121.pNode->RefCount == 1;
  --v78->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v78);
  v79 = v123.pNode;
  v43 = v123.pNode->RefCount == 1;
  --v79->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v79);
  v80 = v99.Flags;
  if ( (v99.Flags & 0x1F) > 9 )
  {
    if ( (v99.Flags >> 9) & 1 )
    {
      v43 = v99.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v99.Bonus.pWeakProxy = 0i64;
      v99.value = 0ui64;
      v99.Flags = v80 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v99);
    }
  }
  v81 = v125.pNode;
  v43 = v125.pNode->RefCount == 1;
  --v81->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v81);
  v82 = v127.pNode;
  v43 = v127.pNode->RefCount == 1;
  --v82->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v82);
  v83 = v129.pNode;
  v43 = v129.pNode->RefCount == 1;
  --v83->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v83);
  v84 = v101.Flags;
  if ( (v101.Flags & 0x1F) > 9 )
  {
    if ( (v101.Flags >> 9) & 1 )
    {
      v43 = v101.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v101.Bonus.pWeakProxy = 0i64;
      v101.value = 0ui64;
      v101.Flags = v84 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v101);
    }
  }
  v85 = v131.pNode;
  v43 = v131.pNode->RefCount == 1;
  --v85->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v85);
  v86 = v133.pNode;
  v43 = v133.pNode->RefCount == 1;
  --v86->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v86);
  v87 = v135.pNode;
  v43 = v135.pNode->RefCount == 1;
  --v87->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v87);
  v88 = v103.Flags;
  if ( (v103.Flags & 0x1F) > 9 )
  {
    if ( (v103.Flags >> 9) & 1 )
    {
      v43 = v103.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v103.Bonus.pWeakProxy = 0i64;
      v103.value = 0ui64;
      v103.Flags = v88 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v103);
    }
  }
  v89 = v137.pNode;
  v43 = v137.pNode->RefCount == 1;
  --v89->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v89);
  v90 = v139.pNode;
  v43 = v139.pNode->RefCount == 1;
  --v90->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v90);
  v91 = v141.pNode;
  v43 = v141.pNode->RefCount == 1;
  --v91->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v91);
  v92 = v105.Flags;
  if ( (v105.Flags & 0x1F) > 9 )
  {
    if ( (v105.Flags >> 9) & 1 )
    {
      v43 = v105.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      v105.Bonus.pWeakProxy = 0i64;
      v105.value = 0ui64;
      v105.Flags = v92 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&v105);
    }
  }
  v93 = v143.pNode;
  v43 = v143.pNode->RefCount == 1;
  --v93->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v93);
  v94 = v145.pNode;
  v43 = v145.pNode->RefCount == 1;
  --v94->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v94);
  v95 = v147.pNode;
  v43 = v147.pNode->RefCount == 1;
  --v95->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v95);
  v96 = value.Flags;
  if ( (value.Flags & 0x1F) > 9 )
  {
    if ( (value.Flags >> 9) & 1 )
    {
      v43 = value.Bonus.pWeakProxy->RefCount-- == 1;
      if ( v43 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
      value.Bonus.pWeakProxy = 0i64;
      value.value = 0ui64;
      value.Flags = v96 & 0xFFFFFDE0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(&value);
    }
  }
  v97 = resulta.pNode;
  v43 = resulta.pNode->RefCount == 1;
  --v97->RefCount;
  if ( v43 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v97);
}

// File Line: 140
// RVA: 0x795830
void __fastcall Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform::AS3Constructor(Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *this, unsigned int argc, Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Value *v3; // rdi
  unsigned int v4; // ebx
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v5; // rsi
  Scaleform::GFx::AS3::CheckResult result; // [rsp+38h] [rbp+10h]

  if ( argc )
  {
    v3 = argv;
    v4 = argc;
    v5 = this;
    if ( Scaleform::GFx::AS3::Value::Convert2Number(argv, &result, &this->redMultiplier)->Result )
    {
      if ( v4 > 1
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 1, &result, &v5->greenMultiplier)->Result
        && v4 > 2
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 2, &result, &v5->blueMultiplier)->Result
        && v4 > 3
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 3, &result, &v5->alphaMultiplier)->Result
        && v4 > 4
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 4, &result, &v5->redOffset)->Result
        && v4 > 5
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 5, &result, &v5->greenOffset)->Result
        && v4 > 6
        && Scaleform::GFx::AS3::Value::Convert2Number(v3 + 6, &result, &v5->blueOffset)->Result
        && v4 > 7 )
      {
        Scaleform::GFx::AS3::Value::Convert2Number(v3 + 7, &result, &v5->alphaOffset);
      }
    }
  }
}

// File Line: 243
// RVA: 0x7FF340
void __fastcall Scaleform::GFx::AS3::InstanceTraits::fl_geom::ColorTransform::MakeObject(Scaleform::GFx::AS3::InstanceTraits::fl_geom::ColorTransform *this, Scaleform::GFx::AS3::Value *result, Scaleform::GFx::AS3::InstanceTraits::Traits *t)
{
  Scaleform::GFx::AS3::Value *v3; // rbx
  Scaleform::GFx::AS3::Object **v4; // rax
  Scaleform::Pickable<Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform> resulta; // [rsp+48h] [rbp+20h]

  v3 = result;
  v4 = (Scaleform::GFx::AS3::Object **)Scaleform::GFx::AS3::InstanceTraits::fl_geom::ColorTransform::MakeInstance(
                                         &resulta,
                                         (Scaleform::GFx::AS3::InstanceTraits::fl_geom::ColorTransform *)t);
  Scaleform::GFx::AS3::Value::Pick(v3, *v4);
}

// File Line: 265
// RVA: 0x7680B0
Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::MakeClassTraits(Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *result, Scaleform::GFx::AS3::VM *vm)
{
  Scaleform::GFx::AS3::VM *v2; // rbp
  Scaleform::Pickable<Scaleform::GFx::AS3::ClassTraits::Traits> *v3; // rdi
  Scaleform::MemoryHeap *v4; // rsi
  Scaleform::GFx::AS3::ClassTraits::Traits *v5; // rax
  Scaleform::GFx::AS3::ClassTraits::Traits *v6; // rbx
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v7; // rax
  Scaleform::GFx::AS3::InstanceTraits::CTraits *v8; // rbx
  Scaleform::GFx::AS3::Class *v9; // rax

  v2 = vm;
  v3 = result;
  v4 = vm->MHeap;
  v5 = (Scaleform::GFx::AS3::ClassTraits::Traits *)v4->vfptr->Alloc(v4, 208ui64, 0i64);
  v6 = v5;
  if ( v5 )
  {
    Scaleform::GFx::AS3::ClassTraits::Traits::Traits(v5, v2, &Scaleform::GFx::AS3::fl_geom::ColorTransformCI);
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl::Object::`vftable;
    v6->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v3->pV = v6;
  v7 = (Scaleform::GFx::AS3::InstanceTraits::CTraits *)v4->vfptr->Alloc(v4, 240ui64, 0i64);
  v8 = v7;
  if ( v7 )
  {
    Scaleform::GFx::AS3::InstanceTraits::CTraits::CTraits(v7, v2, &Scaleform::GFx::AS3::fl_geom::ColorTransformCI);
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl::Object::`vftable;
    v8->vfptr = (Scaleform::GFx::AS3::RefCountBaseGC<328>Vtbl *)&Scaleform::GFx::AS3::InstanceTraits::fl_geom::ColorTransform::`vftable;
  }
  else
  {
    v8 = 0i64;
  }
  Scaleform::GFx::AS3::ClassTraits::Traits::SetInstanceTraits(
    v3->pV,
    (Scaleform::Pickable<Scaleform::GFx::AS3::InstanceTraits::Traits>)v8);
  v9 = (Scaleform::GFx::AS3::Class *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))v4->vfptr->Alloc)(
                                       v4,
                                       72i64);
  if ( v9 )
    Scaleform::GFx::AS3::Class::Class(v9, v3->pV);
  return v3;
}

// File Line: 279
// RVA: 0x7E7540
Scaleform::Render::Cxform *__fastcall Scaleform::GFx::AS3::ClassTraits::fl_geom::ColorTransform::GetCxformFromColorTransform(Scaleform::Render::Cxform *result, Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *value)
{
  Scaleform::GFx::AS3::Instances::fl_geom::ColorTransform *v2; // rdi
  Scaleform::Render::Cxform *v3; // rbx
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm0_4
  float v9; // xmm1_4

  v2 = value;
  v3 = result;
  Scaleform::Render::Cxform::Cxform(result);
  if ( v2 )
  {
    v4 = v2->redMultiplier;
    v3->M[0][0] = v4;
    v5 = v2->greenMultiplier;
    v3->M[0][1] = v5;
    v6 = v2->blueMultiplier;
    v3->M[0][2] = v6;
    v7 = v2->alphaMultiplier;
    v3->M[0][3] = v7;
    v8 = v2->redOffset;
    v3->M[1][0] = v8;
    v9 = v2->greenOffset;
    v3->M[1][1] = v9;
    v3->M[1][2] = v2->blueOffset;
    v3->M[1][3] = v2->alphaOffset;
    Scaleform::Render::Cxform::Normalize(v3);
  }
  return v3;
}

