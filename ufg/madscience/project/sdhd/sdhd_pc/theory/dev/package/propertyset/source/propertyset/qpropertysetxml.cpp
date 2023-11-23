// File Line: 1071
// RVA: 0x1EFD50
char __fastcall UFG::AddBasicPropertyFromNode(
        SimpleXML::XMLDocument *xml_doc,
        SimpleXML::XMLNode *property_node,
        UFG::qArray<unsigned long,0> *property_name,
        UFG::qPropertySet *property_set_data,
        UFG::qPropertyList *property_list_data)
{
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  double v8; // xmm0_8
  double v9; // xmm0_8
  double v10; // xmm0_8
  double v11; // xmm0_8
  double v12; // xmm0_8
  double v13; // xmm0_8
  double v14; // xmm0_8
  double v15; // xmm0_8
  double v16; // xmm0_8
  double v17; // xmm0_8
  double v18; // xmm0_8
  double v19; // xmm0_8
  double v20; // xmm0_8
  double v21; // xmm0_8
  double v22; // xmm0_8
  double v23; // xmm0_8
  double v24; // xmm0_8
  double v25; // xmm0_8
  double v26; // xmm0_8
  double v27; // xmm0_8
  double v28; // xmm0_8
  double v29; // xmm0_8
  double v30; // xmm0_8
  double v31; // xmm0_8
  double v32; // xmm0_8
  char *v33; // rax
  char *Value; // rax
  unsigned int v35; // eax
  bool v37; // [rsp+20h] [rbp-3C8h]
  const char *text_a; // [rsp+28h] [rbp-3C0h]
  char *text; // [rsp+30h] [rbp-3B8h]
  int v40; // [rsp+38h] [rbp-3B0h]
  UFG::qArray<unsigned long,0> v41; // [rsp+3Ch] [rbp-3ACh] BYREF
  unsigned __int16 mHeight; // [rsp+4Ch] [rbp-39Ch]
  AMD_HD3D result; // [rsp+50h] [rbp-398h] BYREF
  float v44; // [rsp+70h] [rbp-378h]
  float v45; // [rsp+74h] [rbp-374h]
  float v46; // [rsp+78h] [rbp-370h]
  float v47; // [rsp+80h] [rbp-368h]
  float v48; // [rsp+84h] [rbp-364h]
  float v49; // [rsp+88h] [rbp-360h]
  float v50; // [rsp+90h] [rbp-358h]
  float v51; // [rsp+94h] [rbp-354h]
  float v52; // [rsp+98h] [rbp-350h]
  float v53; // [rsp+A0h] [rbp-348h]
  float v54; // [rsp+A4h] [rbp-344h]
  float v55; // [rsp+A8h] [rbp-340h]
  UFG::qVector4 *v56; // [rsp+B0h] [rbp-338h]
  float a; // [rsp+B8h] [rbp-330h]
  __int64 v58; // [rsp+BCh] [rbp-32Ch]
  float v59; // [rsp+C4h] [rbp-324h]
  float v60; // [rsp+C8h] [rbp-320h]
  float v61; // [rsp+CCh] [rbp-31Ch]
  float v62; // [rsp+D0h] [rbp-318h]
  float v63; // [rsp+D4h] [rbp-314h]
  float v64; // [rsp+D8h] [rbp-310h]
  float v65; // [rsp+DCh] [rbp-30Ch]
  int v66; // [rsp+E0h] [rbp-308h]
  float v67; // [rsp+E4h] [rbp-304h]
  float v68; // [rsp+E8h] [rbp-300h]
  float v69; // [rsp+ECh] [rbp-2FCh]
  unsigned int v70; // [rsp+F0h] [rbp-2F8h]
  float v71; // [rsp+F4h] [rbp-2F4h]
  float v; // [rsp+F8h] [rbp-2F0h]
  float v73; // [rsp+FCh] [rbp-2ECh]
  float v74; // [rsp+100h] [rbp-2E8h]
  float v75; // [rsp+104h] [rbp-2E4h]
  UFG::qVector4 *v76; // [rsp+108h] [rbp-2E0h]
  UFG::qVector4 *v77; // [rsp+110h] [rbp-2D8h]
  UFG::qMatrix44 *v78; // [rsp+118h] [rbp-2D0h]
  UFG::qVector4 *v79; // [rsp+120h] [rbp-2C8h]
  float x; // [rsp+128h] [rbp-2C0h]
  float v81; // [rsp+130h] [rbp-2B8h]
  int v82; // [rsp+138h] [rbp-2B0h]
  float v83; // [rsp+140h] [rbp-2A8h]
  float v84; // [rsp+148h] [rbp-2A0h]
  float v85; // [rsp+150h] [rbp-298h]
  UFG::qVector2 v86; // [rsp+158h] [rbp-290h] BYREF
  float v87; // [rsp+160h] [rbp-288h]
  SimpleXML::XMLNode *ChildNode; // [rsp+168h] [rbp-280h]
  float v89; // [rsp+170h] [rbp-278h]
  SimpleXML::XMLNode *v90; // [rsp+178h] [rbp-270h]
  float v91; // [rsp+180h] [rbp-268h]
  SimpleXML::XMLNode *v92; // [rsp+188h] [rbp-260h]
  float v93; // [rsp+190h] [rbp-258h]
  UFG::qMatrix44 *v94; // [rsp+198h] [rbp-250h]
  float v95; // [rsp+1A0h] [rbp-248h]
  UFG::qMatrix44 *v96; // [rsp+1A8h] [rbp-240h]
  int v97; // [rsp+1B0h] [rbp-238h]
  float v98; // [rsp+1B8h] [rbp-230h]
  float v99; // [rsp+1BCh] [rbp-22Ch]
  float v100; // [rsp+1C0h] [rbp-228h]
  float v101; // [rsp+1C8h] [rbp-220h]
  float v102; // [rsp+1D0h] [rbp-218h]
  float v103; // [rsp+1D8h] [rbp-210h]
  float v104; // [rsp+1E0h] [rbp-208h]
  float v105; // [rsp+1E8h] [rbp-200h]
  float v106; // [rsp+1F0h] [rbp-1F8h]
  float v107; // [rsp+1F8h] [rbp-1F0h]
  float v108; // [rsp+200h] [rbp-1E8h]
  float v109; // [rsp+204h] [rbp-1E4h]
  int v110; // [rsp+208h] [rbp-1E0h]
  float v111; // [rsp+20Ch] [rbp-1DCh]
  int StartingPos; // [rsp+210h] [rbp-1D8h]
  float y; // [rsp+214h] [rbp-1D4h]
  int v114; // [rsp+218h] [rbp-1D0h]
  float z; // [rsp+220h] [rbp-1C8h]
  int v116; // [rsp+228h] [rbp-1C0h]
  float v117; // [rsp+230h] [rbp-1B8h]
  float v118; // [rsp+238h] [rbp-1B0h]
  float v119; // [rsp+240h] [rbp-1A8h]
  int v120; // [rsp+244h] [rbp-1A4h]
  int v121; // [rsp+248h] [rbp-1A0h]
  float v122; // [rsp+250h] [rbp-198h]
  float v123; // [rsp+258h] [rbp-190h]
  float v124; // [rsp+260h] [rbp-188h]
  float v125; // [rsp+268h] [rbp-180h]
  float v126; // [rsp+270h] [rbp-178h]
  unsigned int w; // [rsp+278h] [rbp-170h]
  float v128; // [rsp+280h] [rbp-168h]
  float v129; // [rsp+288h] [rbp-160h]
  float v130; // [rsp+290h] [rbp-158h]
  float v131; // [rsp+298h] [rbp-150h]
  float v132; // [rsp+2A0h] [rbp-148h]
  int v133; // [rsp+2A8h] [rbp-140h]
  float v134; // [rsp+2B0h] [rbp-138h]
  float v135; // [rsp+2B4h] [rbp-134h]
  float v136; // [rsp+2B8h] [rbp-130h]
  int v137; // [rsp+2BCh] [rbp-12Ch]
  float v138; // [rsp+2C0h] [rbp-128h]
  float v139; // [rsp+2C4h] [rbp-124h]
  float v140; // [rsp+2C8h] [rbp-120h]
  float v141; // [rsp+2D0h] [rbp-118h]
  float v142; // [rsp+2D8h] [rbp-110h]
  float v143; // [rsp+2DCh] [rbp-10Ch]
  float v144; // [rsp+2E0h] [rbp-108h]
  UFG::qVector3 v145; // [rsp+2E8h] [rbp-100h] BYREF
  __int64 v146; // [rsp+2F8h] [rbp-F0h]
  char *v147; // [rsp+300h] [rbp-E8h]
  unsigned __int64 v148; // [rsp+308h] [rbp-E0h]
  UFG::qVector4 v149; // [rsp+310h] [rbp-D8h] BYREF
  UFG::qRangedValue<long> v150; // [rsp+320h] [rbp-C8h] BYREF
  UFG::qTransQuat v151; // [rsp+328h] [rbp-C0h] BYREF
  char *v152; // [rsp+348h] [rbp-A0h]
  char *v153; // [rsp+350h] [rbp-98h]
  char *Attribute; // [rsp+358h] [rbp-90h]
  char *v155; // [rsp+360h] [rbp-88h]
  char *v156; // [rsp+368h] [rbp-80h]
  char *v157; // [rsp+370h] [rbp-78h]
  char *v158; // [rsp+378h] [rbp-70h]
  char *v159; // [rsp+380h] [rbp-68h]
  char *pszSymbolString; // [rsp+388h] [rbp-60h]
  UFG::qMatrix44 v161; // [rsp+390h] [rbp-58h] BYREF
  __int64 v162; // [rsp+3D0h] [rbp-18h]

  v162 = -2i64;
  text_a = SimpleXML::XMLNode::GetAttribute(property_node, "type");
  text = SimpleXML::XMLNode::GetValue(property_node);
  if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Float32", -1) )
  {
    if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Int8", -1) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Int16", -1) )
      {
        if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Int32", -1) )
        {
          if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Int64", -1) )
          {
            if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "UInt8", -1) )
            {
              if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "UInt16", -1) )
              {
                if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "UInt32", -1) )
                {
                  if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "UInt64", -1) )
                  {
                    if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Boolean", -1) )
                    {
                      if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "String", -1) )
                      {
                        if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Symbol", -1) )
                        {
                          if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "SymbolUC", -1) )
                          {
                            if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "WwiseID", -1) )
                            {
                              if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Vector2", -1) )
                              {
                                if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Vector3", -1) )
                                {
                                  if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Vector4", -1) )
                                  {
                                    if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "TransQuat", -1) )
                                    {
                                      if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "TransRotation", -1) )
                                      {
                                        if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "Int32Ranged", -1) )
                                        {
                                          if ( (unsigned int)UFG::qStringCompareInsensitive(
                                                               text_a,
                                                               "WeightedListProperty",
                                                               -1) )
                                          {
                                            if ( (unsigned int)UFG::qStringCompareInsensitive(
                                                                 text_a,
                                                                 "Float32Ranged",
                                                                 -1) )
                                              return 0;
                                          }
                                          else
                                          {
                                            Attribute = SimpleXML::XMLNode::GetAttribute(property_node, "weight", "1");
                                            Value = SimpleXML::XMLNode::GetValue(property_node);
                                            UFG::qSymbol::create_from_string((UFG::qSymbol *)&v41.p, Value);
                                            w = UFG::qToInt32(Attribute, 0);
                                            v158 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v41.p);
                                            v35 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v41.p);
                                            _((AMD_HD3D *)v35);
                                            if ( property_set_data )
                                              UFG::qPropertySet::Set<UFG::qSymbol>(
                                                property_set_data,
                                                property_name,
                                                (UFG::qSymbol *)&v41.p);
                                            if ( property_list_data )
                                            {
                                              UFG::qPropertyList::Add<UFG::qSymbol>(
                                                property_list_data,
                                                (UFG::qSymbol *)&v41.p);
                                              StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)property_list_data);
                                              UFG::qPropertyList::SetWeight(property_list_data, StartingPos - 1, w);
                                            }
                                            _((AMD_HD3D *)&v41.p);
                                          }
                                        }
                                        else
                                        {
                                          v153 = SimpleXML::XMLNode::GetAttribute(property_node, "range", "100");
                                          v150.mRange = UFG::qToInt32(v153, 0);
                                          v33 = SimpleXML::XMLNode::GetValue(property_node);
                                          v150.mValue = UFG::qToInt32(v33, 0);
                                          if ( property_set_data )
                                            UFG::qPropertySet::Set<UFG::qRangedValue<long>>(
                                              property_set_data,
                                              property_name,
                                              &v150);
                                        }
                                      }
                                      else
                                      {
                                        ChildNode = SimpleXML::XMLDocument::GetChildNode(
                                                      xml_doc,
                                                      "Translation",
                                                      property_node);
                                        v90 = SimpleXML::XMLDocument::GetChildNode(xml_doc, "Forward", property_node);
                                        v92 = SimpleXML::XMLDocument::GetChildNode(xml_doc, "Up", property_node);
                                        v24 = SimpleXML::XMLNode::GetAttribute(ChildNode, "z", 0.0);
                                        v133 = LODWORD(v24);
                                        v25 = SimpleXML::XMLNode::GetAttribute(ChildNode, "y", 0.0);
                                        v114 = LODWORD(v25);
                                        v26 = SimpleXML::XMLNode::GetAttribute(ChildNode, "x", 0.0);
                                        v97 = LODWORD(v26);
                                        v119 = *(float *)&v26;
                                        v120 = v114;
                                        v121 = v133;
                                        v27 = SimpleXML::XMLNode::GetAttribute(v90, "z", 0.0);
                                        v81 = *(float *)&v27;
                                        v28 = SimpleXML::XMLNode::GetAttribute(v90, "y", 0.0);
                                        v129 = *(float *)&v28;
                                        v29 = SimpleXML::XMLNode::GetAttribute(v90, "x", 0.0);
                                        v116 = LODWORD(v29);
                                        v53 = *(float *)&v29;
                                        v54 = v129;
                                        v55 = v81;
                                        v30 = SimpleXML::XMLNode::GetAttribute(v92, "z", 0.0);
                                        v117 = *(float *)&v30;
                                        v31 = SimpleXML::XMLNode::GetAttribute(v92, "y", 0.0);
                                        v84 = *(float *)&v31;
                                        v32 = SimpleXML::XMLNode::GetAttribute(v92, "x", 0.0);
                                        v82 = LODWORD(v32);
                                        v47 = *(float *)&v32;
                                        v48 = v84;
                                        v49 = v117;
                                        Assembly::GetRCX(&v161);
                                        a = (float)((float)(v47 * v47) + (float)(v48 * v48)) + (float)(v49 * v49);
                                        if ( a == 0.0 )
                                          v65 = 0.0;
                                        else
                                          v65 = UFG::qRSqrt(a);
                                        *(float *)&result.mStereo = v65;
                                        v126 = v49 * v65;
                                        v124 = v48 * v65;
                                        v122 = v47 * v65;
                                        v73 = v47 * v65;
                                        v74 = v48 * v65;
                                        v75 = v49 * v65;
                                        v67 = (float)((float)(v53 * v53) + (float)(v54 * v54)) + (float)(v55 * v55);
                                        if ( v67 == 0.0 )
                                          v69 = 0.0;
                                        else
                                          v69 = UFG::qRSqrt(v67);
                                        v46 = v69;
                                        v132 = v55 * v69;
                                        v130 = v54 * v69;
                                        v128 = v53 * v69;
                                        v134 = v53 * v69;
                                        v135 = v54 * v69;
                                        v136 = v55 * v69;
                                        v78 = &v161;
                                        v98 = v53 * v69;
                                        v83 = v54 * v69;
                                        v99 = v55 * v69;
                                        v161.v0.x = v53 * v69;
                                        v161.v0.y = v54 * v69;
                                        v161.v0.z = v55 * v69;
                                        v161.v0.w = 0.0;
                                        v94 = &v161;
                                        v85 = v53 * v69;
                                        v101 = v54 * v69;
                                        v87 = v55 * v69;
                                        v60 = v53 * v69;
                                        v61 = v54 * v69;
                                        v62 = v55 * v69;
                                        v105 = (float)(v73 * (float)(v54 * v69)) - (float)(v74 * (float)(v53 * v69));
                                        v89 = (float)(v75 * (float)(v53 * v69)) - (float)(v73 * (float)(v55 * v69));
                                        v103 = (float)(v74 * (float)(v55 * v69)) - (float)(v75 * (float)(v54 * v69));
                                        v50 = v103;
                                        v51 = v89;
                                        v52 = v105;
                                        v71 = (float)((float)(v50 * v50) + (float)(v89 * v89)) + (float)(v105 * v105);
                                        if ( v71 == 0.0 )
                                          v63 = 0.0;
                                        else
                                          v63 = UFG::qRSqrt(v71);
                                        *((float *)&result.mStereo + 1) = v63;
                                        v93 = v52 * v63;
                                        v107 = v51 * v63;
                                        v91 = v50 * v63;
                                        v138 = v50 * v63;
                                        v139 = v51 * v63;
                                        v140 = v52 * v63;
                                        v76 = &v161.v1;
                                        v109 = v50 * v63;
                                        v95 = v51 * v63;
                                        v111 = v52 * v63;
                                        v161.v1.x = v50 * v63;
                                        v161.v1.y = v51 * v63;
                                        v161.v1.z = v52 * v63;
                                        v161.v1.w = 0.0;
                                        v96 = &v161;
                                        y = v161.v0.y;
                                        x = v161.v0.x;
                                        z = v161.v0.z;
                                        v58 = *(_QWORD *)&v161.v0.x;
                                        v59 = v161.v0.z;
                                        v56 = &v161.v1;
                                        v102 = (float)(v161.v0.x * (float)(v51 * v63))
                                             - (float)(v161.v0.y * (float)(v50 * v63));
                                        v118 = (float)(v161.v0.z * (float)(v50 * v63))
                                             - (float)(v161.v0.x * (float)(v52 * v63));
                                        v100 = (float)(v161.v0.y * (float)(v52 * v63))
                                             - (float)(v161.v0.z * (float)(v51 * v63));
                                        *((float *)&result.mExtension + 1) = v100;
                                        v44 = v118;
                                        v45 = v102;
                                        v68 = (float)((float)(v100 * v100) + (float)(v118 * v118))
                                            + (float)(v102 * v102);
                                        if ( v68 == 0.0 )
                                          v64 = 0.0;
                                        else
                                          v64 = UFG::qRSqrt(v68);
                                        *(float *)&result.mExtension = v64;
                                        v123 = v45 * v64;
                                        v104 = v44 * v64;
                                        v141 = *((float *)&result.mExtension + 1) * v64;
                                        v142 = *((float *)&result.mExtension + 1) * v64;
                                        v143 = v44 * v64;
                                        v144 = v45 * v64;
                                        v77 = &v161.v2;
                                        v106 = *((float *)&result.mExtension + 1) * v64;
                                        v131 = v44 * v64;
                                        v108 = v45 * v64;
                                        v161.v2.x = *((float *)&result.mExtension + 1) * v64;
                                        v161.v2.y = v44 * v64;
                                        v161.v2.z = v45 * v64;
                                        v161.v2.w = 0.0;
                                        v79 = &v161.v3;
                                        v125 = v119;
                                        v110 = v120;
                                        v137 = v121;
                                        v161.v3.x = v119;
                                        LODWORD(v161.v3.y) = v120;
                                        LODWORD(v161.v3.z) = v121;
                                        LODWORD(v161.v3.w) = (_DWORD)FLOAT_1_0;
                                        if ( property_set_data )
                                          UFG::qPropertySet::Set<UFG::qMatrix44>(
                                            property_set_data,
                                            property_name,
                                            &v161);
                                        if ( property_list_data )
                                          UFG::qPropertyList::Add<UFG::qMatrix44>(property_list_data, &v161);
                                      }
                                    }
                                    else
                                    {
                                      UFG::qTransQuat::qTransQuat(&v151);
                                      v17 = SimpleXML::XMLNode::GetAttribute(property_node, "tx", 0.0);
                                      v151.mTrans.x = *(float *)&v17;
                                      v18 = SimpleXML::XMLNode::GetAttribute(property_node, "ty", 0.0);
                                      v151.mTrans.y = *(float *)&v18;
                                      v19 = SimpleXML::XMLNode::GetAttribute(property_node, "tz", 0.0);
                                      v151.mTrans.z = *(float *)&v19;
                                      v20 = SimpleXML::XMLNode::GetAttribute(property_node, "rx", 0.0);
                                      v151.mRot.x = *(float *)&v20;
                                      v21 = SimpleXML::XMLNode::GetAttribute(property_node, "ry", 0.0);
                                      v151.mRot.y = *(float *)&v21;
                                      v22 = SimpleXML::XMLNode::GetAttribute(property_node, "rz", 0.0);
                                      v151.mRot.z = *(float *)&v22;
                                      v23 = SimpleXML::XMLNode::GetAttribute(property_node, "rw", 0.0);
                                      v151.mRot.w = *(float *)&v23;
                                      if ( property_set_data )
                                        UFG::qPropertySet::Set<UFG::qTransQuat>(property_set_data, property_name, &v151);
                                      if ( property_list_data )
                                        UFG::qPropertyList::Add<UFG::qTransQuat>(property_list_data, &v151);
                                    }
                                  }
                                  else
                                  {
                                    v13 = SimpleXML::XMLNode::GetAttribute(property_node, "x", 0.0);
                                    v149.x = *(float *)&v13;
                                    v14 = SimpleXML::XMLNode::GetAttribute(property_node, "y", 0.0);
                                    v149.y = *(float *)&v14;
                                    v15 = SimpleXML::XMLNode::GetAttribute(property_node, "z", 0.0);
                                    v149.z = *(float *)&v15;
                                    v16 = SimpleXML::XMLNode::GetAttribute(property_node, "w", 0.0);
                                    v149.w = *(float *)&v16;
                                    if ( property_set_data )
                                      UFG::qPropertySet::Set<UFG::qVector4>(property_set_data, property_name, &v149);
                                    if ( property_list_data )
                                      UFG::qPropertyList::Add<UFG::qVector4>(property_list_data, &v149);
                                  }
                                }
                                else
                                {
                                  v10 = SimpleXML::XMLNode::GetAttribute(property_node, "x", 0.0);
                                  v145.x = *(float *)&v10;
                                  v11 = SimpleXML::XMLNode::GetAttribute(property_node, "y", 0.0);
                                  v145.y = *(float *)&v11;
                                  v12 = SimpleXML::XMLNode::GetAttribute(property_node, "z", 0.0);
                                  v145.z = *(float *)&v12;
                                  if ( property_set_data )
                                    UFG::qPropertySet::Set<UFG::qVector3>(property_set_data, property_name, &v145);
                                  if ( property_list_data )
                                    UFG::qPropertyList::Add<UFG::qVector3>(property_list_data, &v145);
                                }
                              }
                              else
                              {
                                v8 = SimpleXML::XMLNode::GetAttribute(property_node, "x", 0.0);
                                v86.x = *(float *)&v8;
                                v9 = SimpleXML::XMLNode::GetAttribute(property_node, "y", 0.0);
                                v86.y = *(float *)&v9;
                                if ( property_set_data )
                                  UFG::qPropertySet::Set<UFG::qVector2>(property_set_data, property_name, &v86);
                                if ( property_list_data )
                                  UFG::qPropertyList::Add<UFG::qVector2>(property_list_data, &v86);
                              }
                            }
                            else
                            {
                              v155 = text;
                              UFG::qWiseSymbol::create_from_string((UFG::qWiseSymbol *)&v41, text);
                              v156 = UFG::qWiseSymbol::as_cstr_dbg((UFG::qWiseSymbol *)&v41);
                              v7 = UFG::qSymbolUC::as_uint32(&v41);
                              _((AMD_HD3D *)v7);
                              if ( property_set_data )
                                UFG::qPropertySet::Set<UFG::qWiseSymbol>(
                                  property_set_data,
                                  property_name,
                                  (UFG::qWiseSymbol *)&v41);
                              if ( property_list_data )
                                UFG::qPropertyList::Add<UFG::qWiseSymbol>(property_list_data, (UFG::qWiseSymbol *)&v41);
                              UFG::qWiseSymbol::~qWiseSymbol((UFG::qWiseSymbol *)&v41);
                            }
                          }
                          else
                          {
                            v159 = text;
                            UFG::qSymbolUC::create_from_string((UFG::qSymbolUC *)&v41.p + 1, text);
                            v152 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v41.p + 1);
                            v6 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)((char *)&v41.p + 4));
                            _((AMD_HD3D *)v6);
                            if ( property_set_data )
                              UFG::qPropertySet::Set<UFG::qSymbolUC>(
                                property_set_data,
                                property_name,
                                (UFG::qSymbolUC *)&v41.p + 1);
                            if ( property_list_data )
                              UFG::qPropertyList::Add<UFG::qSymbolUC>(property_list_data, (UFG::qSymbolUC *)&v41.p + 1);
                            _((AMD_HD3D *)((char *)&v41.p + 4));
                          }
                        }
                        else
                        {
                          pszSymbolString = text;
                          UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, text);
                          v157 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
                          v5 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
                          _((AMD_HD3D *)v5);
                          if ( property_set_data )
                            UFG::qPropertySet::Set<UFG::qSymbol>(
                              property_set_data,
                              property_name,
                              (UFG::qSymbol *)&result);
                          if ( property_list_data )
                            UFG::qPropertyList::Add<UFG::qSymbol>(property_list_data, (UFG::qSymbol *)&result);
                          _(&result);
                        }
                      }
                      else
                      {
                        v147 = text;
                        if ( property_set_data )
                          UFG::qPropertySet::Set<char const *>(property_set_data, property_name, v147);
                        if ( property_list_data )
                          UFG::qPropertyList::Add<char const *>(property_list_data, v147);
                      }
                    }
                    else
                    {
                      v37 = UFG::qToBool(text, 0);
                      if ( property_set_data )
                        UFG::qPropertySet::Set<bool>(property_set_data, property_name, v37);
                      if ( property_list_data )
                        UFG::qPropertyList::Add<bool>(property_list_data, v37);
                    }
                  }
                  else
                  {
                    v148 = UFG::qToUInt64(text, 0i64);
                    if ( property_set_data )
                      UFG::qPropertySet::Set<unsigned __int64>(property_set_data, property_name, v148);
                    if ( property_list_data )
                      UFG::qPropertyList::Add<unsigned __int64>(property_list_data, v148);
                  }
                }
                else
                {
                  v70 = UFG::qToUInt32(text, 0);
                  if ( property_set_data )
                    UFG::qPropertySet::Set<unsigned long>(property_set_data, property_name, v70);
                  if ( property_list_data )
                    UFG::qPropertyList::Add<unsigned long>(property_list_data, v70);
                }
              }
              else
              {
                result.mHeight = UFG::qToUInt32(text, 0);
                if ( result.mHeight > 0xFFFF )
                  result.mHeight = 0xFFFF;
                mHeight = result.mHeight;
                if ( property_set_data )
                  UFG::qPropertySet::Set<unsigned short>(property_set_data, property_name, mHeight);
                if ( property_list_data )
                  UFG::qPropertyList::Add<unsigned short>(property_list_data, mHeight);
              }
            }
            else
            {
              result.mWidth = UFG::qToUInt32(text, 0);
              if ( result.mWidth > 0xFF )
                result.mWidth = 255;
              if ( property_set_data )
                UFG::qPropertySet::Set<unsigned char>(property_set_data, property_name, result.mWidth);
              if ( property_list_data )
                UFG::qPropertyList::Add<unsigned char>(property_list_data, result.mWidth);
            }
          }
          else
          {
            v146 = UFG::qToInt64(text, 0i64);
            if ( property_set_data )
              UFG::qPropertySet::Set<__int64>(property_set_data, property_name, v146);
            if ( property_list_data )
              UFG::qPropertyList::Add<__int64>(property_list_data, v146);
          }
        }
        else
        {
          v66 = UFG::qToInt32(text, 0);
          if ( property_set_data )
            UFG::qPropertySet::Set<long>(property_set_data, property_name, v66);
          if ( property_list_data )
            UFG::qPropertyList::Add<long>(property_list_data, v66);
        }
      }
      else
      {
        v40 = UFG::qToInt32(text, 0);
        if ( v40 >= -32768 )
        {
          if ( v40 > 0x7FFF )
            LOWORD(v40) = 0x7FFF;
        }
        else
        {
          LOWORD(v40) = 0x8000;
        }
        LOWORD(v41.capacity) = v40;
        if ( property_set_data )
          UFG::qPropertySet::Set<short>(property_set_data, property_name, v41.capacity);
        if ( property_list_data )
          UFG::qPropertyList::Add<short>(property_list_data, v41.capacity);
      }
    }
    else
    {
      result.mLineOffset = UFG::qToInt32(text, 0);
      if ( (int)result.mLineOffset >= -128 )
      {
        if ( (int)result.mLineOffset > 127 )
          result.mLineOffset = 127;
      }
      else
      {
        result.mLineOffset = -128;
      }
      if ( property_set_data )
        UFG::qPropertySet::Set<signed char>(property_set_data, property_name, result.mLineOffset);
      if ( property_list_data )
        UFG::qPropertyList::Add<signed char>(property_list_data, result.mLineOffset);
    }
  }
  else
  {
    v = UFG::qToFloat(text, 0.0);
    if ( property_set_data )
      UFG::qPropertySet::Set<float>(property_set_data, property_name, v);
    if ( property_list_data )
      UFG::qPropertyList::Add<float>(property_list_data, v);
  }
  return 1;
}

// File Line: 1311
// RVA: 0x1EFC00
void __fastcall UFG::AddAllSchemaDefs(
        UFG::qPropertySet *property_set,
        UFG::qArray<UFG::SchemaDef *,0> *schemas_in_parent)
{
  UFG::qSymbol *PropertyNameFromIndex; // rax
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int index; // [rsp+24h] [rbp-34h]
  unsigned int parent_index; // [rsp+28h] [rbp-30h]
  int v6; // [rsp+2Ch] [rbp-2Ch]
  unsigned int v7; // [rsp+30h] [rbp-28h]
  unsigned int v8; // [rsp+34h] [rbp-24h]
  UFG::SchemaDef *SchemaForComponentPropertyName; // [rsp+38h] [rbp-20h]
  unsigned int size; // [rsp+40h] [rbp-18h]
  UFG::qPropertySet *property_seta; // [rsp+48h] [rbp-10h]

  v7 = UFG::qPropertySet::NumProperties(property_set);
  for ( index = 0; index < v7; ++index )
  {
    PropertyNameFromIndex = UFG::qPropertySet::GetPropertyNameFromIndex(property_set, index);
    SchemaForComponentPropertyName = UFG::PropertySetManager::GetSchemaForComponentPropertyName(PropertyNameFromIndex);
    if ( SchemaForComponentPropertyName )
    {
      for ( i = 0; i < schemas_in_parent->size; ++i )
      {
        if ( SchemaForComponentPropertyName == schemas_in_parent->p[i] )
        {
          v6 = i;
          goto LABEL_10;
        }
      }
      v6 = -1;
LABEL_10:
      if ( v6 == -1 )
      {
        size = schemas_in_parent->size;
        UFG::qArray<UFG::SchemaDef *,0>::Grow(schemas_in_parent, 1u, "qArray.Add");
        schemas_in_parent->p[size] = SchemaForComponentPropertyName;
      }
    }
  }
  v8 = UFG::qPropertySet::NumParents(property_set);
  for ( parent_index = 0; parent_index < v8; ++parent_index )
  {
    property_seta = UFG::qPropertySet::GetParentFromIdx(property_set, parent_index);
    UFG::AddAllSchemaDefs(property_seta, schemas_in_parent);
  }
}

// File Line: 1335
// RVA: 0x1F41B0
void __fastcall UFG::CreateNeededSchemaSetsFromParentHierarchy(UFG::qPropertySet *property_set)
{
  UFG::qSymbol *SchemaName; // rax
  UFG::qSymbol *Name; // rax
  unsigned int j; // [rsp+20h] [rbp-E8h]
  unsigned int index; // [rsp+24h] [rbp-E4h]
  unsigned int n; // [rsp+28h] [rbp-E0h]
  unsigned int k; // [rsp+2Ch] [rbp-DCh]
  unsigned int m; // [rsp+30h] [rbp-D8h]
  unsigned int ii; // [rsp+34h] [rbp-D4h]
  UFG::qArray<UFG::SchemaDef *,0> v9; // [rsp+38h] [rbp-D0h] BYREF
  unsigned int parent_index; // [rsp+48h] [rbp-C0h]
  unsigned int i; // [rsp+4Ch] [rbp-BCh]
  unsigned int v12; // [rsp+50h] [rbp-B8h]
  unsigned int v13; // [rsp+54h] [rbp-B4h]
  unsigned int v14; // [rsp+58h] [rbp-B0h]
  UFG::qPropertySet *property_seta; // [rsp+60h] [rbp-A8h]
  UFG::qArray<UFG::SchemaDef *,0> schemas_in_parent; // [rsp+68h] [rbp-A0h] BYREF
  UFG::qArray<UFG::SchemaDef *,0> v17; // [rsp+78h] [rbp-90h] BYREF
  unsigned int v18; // [rsp+88h] [rbp-80h]
  unsigned int v19; // [rsp+8Ch] [rbp-7Ch]
  unsigned int size; // [rsp+90h] [rbp-78h]
  unsigned int v21; // [rsp+94h] [rbp-74h]
  unsigned int v22; // [rsp+98h] [rbp-70h]
  unsigned int v23; // [rsp+9Ch] [rbp-6Ch]
  unsigned int v24; // [rsp+A0h] [rbp-68h]
  UFG::SchemaDef **v25; // [rsp+A8h] [rbp-60h]
  UFG::SchemaDef **v26; // [rsp+B0h] [rbp-58h]
  UFG::SchemaDef **v27; // [rsp+B8h] [rbp-50h]
  UFG::SchemaDef *component_schema; // [rsp+C0h] [rbp-48h]
  UFG::SchemaDef **v29; // [rsp+C8h] [rbp-40h]
  UFG::SchemaDef **v30; // [rsp+D0h] [rbp-38h]
  UFG::SchemaDef **v31; // [rsp+D8h] [rbp-30h]
  UFG::qPropertySet *ParentFromIdx; // [rsp+E0h] [rbp-28h]
  UFG::SchemaDef **v33; // [rsp+E8h] [rbp-20h]
  UFG::SchemaDef **v34; // [rsp+F0h] [rbp-18h]
  __int64 v35; // [rsp+F8h] [rbp-10h]

  v35 = -2i64;
  for ( parent_index = UFG::qPropertySet::NumParents(property_set) - 1; (parent_index & 0x80000000) == 0; --parent_index )
  {
    property_seta = UFG::qPropertySet::GetParentFromIdx(property_set, parent_index);
    if ( UFG::PropertySetManager::IsComponentPropertySet(property_seta) )
    {
      SchemaName = UFG::qPropertySet::GetSchemaName(property_seta);
      component_schema = UFG::PropertySetManager::GetSchema(SchemaName);
      UFG::PropertySetManager::AddComponentPropertySet(property_set, component_schema, property_seta);
      Name = UFG::qPropertySet::GetName(property_seta);
      UFG::qPropertySet::RemoveParent(property_set, Name);
    }
  }
  v17.p = 0i64;
  v17.size = 0;
  v17.capacity = 0;
  v9.p = 0i64;
  v9.size = 0;
  v9.capacity = 0;
  v12 = UFG::qPropertySet::NumParents(property_set);
  for ( i = 0; i < v12; ++i )
  {
    ParentFromIdx = UFG::qPropertySet::GetParentFromIdx(property_set, i);
    schemas_in_parent.p = 0i64;
    schemas_in_parent.size = 0;
    schemas_in_parent.capacity = 0;
    UFG::AddAllSchemaDefs(ParentFromIdx, &schemas_in_parent);
    for ( j = 0; ; ++j )
    {
      size = schemas_in_parent.size;
      if ( j >= schemas_in_parent.size )
        break;
      v34 = &schemas_in_parent.p[j];
      for ( k = 0; k < v17.size; ++k )
      {
        if ( *v34 == v17.p[k] )
        {
          v14 = k;
          goto LABEL_17;
        }
      }
      v14 = -1;
LABEL_17:
      if ( v14 == -1 )
      {
        v33 = &schemas_in_parent.p[j];
        v19 = v17.size;
        UFG::qArray<UFG::SchemaDef *,0>::Grow(&v17, 1u, "qArray.Add");
        v17.p[v19] = *v33;
      }
      else
      {
        v31 = &schemas_in_parent.p[j];
        for ( m = 0; m < v9.size; ++m )
        {
          if ( *v31 == v9.p[m] )
          {
            v13 = m;
            goto LABEL_25;
          }
        }
        v13 = -1;
LABEL_25:
        if ( v13 == -1 )
        {
          v25 = &schemas_in_parent.p[j];
          v22 = v9.size;
          UFG::qArray<UFG::SchemaDef *,0>::Grow(&v9, 1u, "qArray.Add");
          v9.p[v22] = *v25;
        }
      }
    }
    UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&schemas_in_parent);
  }
  v24 = v9.size;
  if ( v9.size )
  {
    for ( index = 0; ; ++index )
    {
      v23 = v9.size;
      if ( index >= v9.size )
        break;
      for ( n = index + 1; ; ++n )
      {
        v18 = v9.size;
        if ( n >= v9.size )
          break;
        v29 = &v9.p[index];
        v30 = &v9.p[n];
        if ( UFG::SchemaDef::IsDerivedFrom(*v30, *v29) )
        {
          UFG::qArray<UFG::SchemaDef *,0>::StableDelete(&v9, index);
        }
        else
        {
          v26 = &v9.p[n];
          v27 = &v9.p[index];
          if ( UFG::SchemaDef::IsDerivedFrom(*v27, *v26) )
            UFG::qArray<UFG::SchemaDef *,0>::StableDelete(&v9, n);
        }
      }
    }
    for ( ii = 0; ; ++ii )
    {
      v21 = v9.size;
      if ( ii >= v9.size )
        break;
      UFG::PropertySetManager::AddComponentPropertySet(property_set, v9.p[ii], 0i64);
    }
  }
  UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&v9);
  UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&v17);
}

// File Line: 1409
// RVA: 0x1FA580
void __fastcall UFG::PostLoadSchemaCreateCheck(
        UFG::qPropertySet *property_set,
        const char *schema_type,
        char *skipparentcheck)
{
  UFG::qSymbol *SchemaName; // rax
  UFG::qSymbol *v4; // rax
  UFG::qArray<unsigned long,0> *Name; // rax
  UFG::qArray<unsigned long,0> *v6; // rax
  UFG::SchemaDef *v7; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *ParentSchemaSet; // [rsp+28h] [rbp-30h]
  UFG::SchemaDef *Schema; // [rsp+30h] [rbp-28h]
  UFG::qSymbol *sym; // [rsp+38h] [rbp-20h]

  if ( property_set )
  {
    SchemaName = UFG::qPropertySet::GetSchemaName(property_set);
    if ( UFG::qSymbol::operator!=(SchemaName, &UFG::gNullQSymbol) )
    {
      sym = UFG::qPropertySet::GetName(property_set);
      v4 = UFG::qPropertySet::GetSchemaName(property_set);
      if ( UFG::qSymbol::operator==(v4, sym) )
      {
        ParentSchemaSet = UFG::PropertySetManager::GetParentSchemaSet(property_set);
        if ( ParentSchemaSet )
        {
          Name = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(ParentSchemaSet);
          Schema = UFG::PropertySetManager::GetSchema(Name);
        }
        else
        {
          Schema = 0i64;
        }
        v6 = (UFG::qArray<unsigned long,0> *)UFG::qPropertySet::GetName(property_set);
        UFG::PropertySetManager::GetSchema(v6);
        v7 = UFG::PropertySetManager::AddSchemaDef(property_set, Schema);
        if ( schema_type && *schema_type )
        {
          if ( !(unsigned int)UFG::qStringCompareInsensitive(schema_type, "component", -1) )
          {
            UFG::SchemaDef::SetComponentSchema(v7, 1);
            UFG::qPropertyCollection::SetFlags(property_set, 0x100000);
          }
        }
        else if ( (unsigned int)UFG::qPropertyCollection::GetFlags(property_set, 0x100000) )
        {
          UFG::SchemaDef::SetComponentSchema(v7, 1);
        }
        if ( skipparentcheck && *skipparentcheck )
        {
          if ( UFG::qToBool(skipparentcheck, 0) )
          {
            UFG::SchemaDef::SetSkipParentCheck(v7, 1);
            UFG::qPropertyCollection::SetFlags(property_set, 0x200000);
          }
        }
        else if ( (unsigned int)UFG::qPropertyCollection::GetFlags(property_set, 0x200000) )
        {
          UFG::SchemaDef::SetSkipParentCheck(v7, 1);
        }
      }
    }
  }
}

// File Line: 1466
// RVA: 0x146BF50
__int64 UFG::_dynamic_initializer_for__sSimObjChildren__()
{
  UFG::qStaticSymbol::qStaticSymbol(&sSimObjChildren, "SimObjChildren");
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__sSimObjChildren__);
}

// File Line: 1473
// RVA: 0x1F5940
__int64 __fastcall UFG::FromXMLNode(
        UFG::qPropertySet *property_set,
        UFG::qPropertyList *property_list_data,
        SimpleXML::XMLDocument *xml_doc,
        SimpleXML::XMLNode *propertyset_node)
{
  unsigned int v4; // eax
  UFG::qSymbol *SchemaName; // rax
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rax
  UFG::qSymbolUC *v15; // rax
  char *v16; // rax
  char *Filename; // rax
  hkSeekableStreamReader *v18; // rax
  UFG::qSymbol *v19; // rax
  UFG::qSymbolUC *v20; // rax
  char *v21; // rax
  hkSeekableStreamReader *v22; // rax
  unsigned int v23; // eax
  char v24; // al
  UFG::qPropertySet *v25; // rax
  char v26; // al
  UFG::qSymbol *v27; // rax
  unsigned __int8 v29; // [rsp+30h] [rbp-198h]
  UFG::qSymbol propertyName; // [rsp+34h] [rbp-194h] BYREF
  char v31; // [rsp+38h] [rbp-190h]
  char v32; // [rsp+39h] [rbp-18Fh]
  SimpleXML::XMLNode *node; // [rsp+40h] [rbp-188h]
  UFG::qPropertySet *property_seta; // [rsp+48h] [rbp-180h]
  UFG::qPropertySet *property_set_data; // [rsp+50h] [rbp-178h]
  unsigned int index; // [rsp+58h] [rbp-170h]
  SimpleXML::XMLNode *i; // [rsp+60h] [rbp-168h]
  char *text_a; // [rsp+68h] [rbp-160h]
  UFG::qPropertyList *v; // [rsp+70h] [rbp-158h]
  AMD_HD3D v40; // [rsp+78h] [rbp-150h] BYREF
  char *pszSymbolString; // [rsp+98h] [rbp-130h]
  UFG::SchemaDef *component_schema; // [rsp+A0h] [rbp-128h]
  UFG::qPropertySet *ParentFromIdx; // [rsp+A8h] [rbp-120h]
  UFG::qSymbol v45; // [rsp+B4h] [rbp-114h] BYREF
  unsigned int StartingPos; // [rsp+B8h] [rbp-110h]
  hkSeekableStreamReader *Attribute; // [rsp+C0h] [rbp-108h]
  int v48; // [rsp+C8h] [rbp-100h]
  char *v49; // [rsp+D0h] [rbp-F8h]
  AMD_HD3D result; // [rsp+D8h] [rbp-F0h] BYREF
  UFG::qPropertySet *v51; // [rsp+F8h] [rbp-D0h]
  UFG::qPropertySet *v52; // [rsp+100h] [rbp-C8h]
  const char *v53; // [rsp+108h] [rbp-C0h]
  UFG::qPropertySet *v54; // [rsp+110h] [rbp-B8h]
  UFG::qSymbol *name; // [rsp+118h] [rbp-B0h]
  char *v56; // [rsp+120h] [rbp-A8h]
  SimpleXML::XMLNode *propertyset_nodea; // [rsp+128h] [rbp-A0h]
  UFG::qSymbol *v58; // [rsp+130h] [rbp-98h]
  UFG::qPropertySet *v59; // [rsp+138h] [rbp-90h]
  UFG::qSymbol *sym; // [rsp+140h] [rbp-88h]
  SimpleXML::XMLNode *ChildNode; // [rsp+148h] [rbp-80h]
  UFG::qSymbol *v62; // [rsp+150h] [rbp-78h]
  UFG::SchemaDef *Schema; // [rsp+158h] [rbp-70h]
  hkSeekableStreamReader *RCX; // [rsp+160h] [rbp-68h]
  char *v65; // [rsp+168h] [rbp-60h]
  UFG::qSymbol *v66; // [rsp+170h] [rbp-58h]
  char *text; // [rsp+178h] [rbp-50h]
  UFG::qSymbol *v68; // [rsp+180h] [rbp-48h]
  char *Value; // [rsp+188h] [rbp-40h]
  hkSeekableStreamReader *v70; // [rsp+190h] [rbp-38h]
  char *skipparentcheck; // [rsp+198h] [rbp-30h]
  UFG::qSymbol *v72; // [rsp+1A0h] [rbp-28h]
  char *schema_type; // [rsp+1A8h] [rbp-20h]
  UFG::qSymbol *v74; // [rsp+1B0h] [rbp-18h]
  __int64 v75; // [rsp+1B8h] [rbp-10h]

  v75 = -2i64;
  v29 = 1;
  pszSymbolString = SimpleXML::XMLNode::GetAttribute(propertyset_node, "name");
  text_a = SimpleXML::XMLNode::GetAttribute(propertyset_node, "schema");
  schema_type = SimpleXML::XMLNode::GetAttribute(propertyset_node, "schematype");
  skipparentcheck = SimpleXML::XMLNode::GetAttribute(propertyset_node, "skipparentcheck");
  v32 = 0;
  if ( property_set )
  {
    if ( pszSymbolString && *pszSymbolString )
    {
      v66 = UFG::qSymbol::create_from_string((UFG::qSymbol *)&result, pszSymbolString);
      name = v66;
      UFG::qPropertySet::SetName(property_set, v66);
      _(&result);
    }
    for ( v40.mExtension = (IAmdDxExt *)SimpleXML::XMLDocument::GetChildNode(xml_doc, "Parent", propertyset_node);
          v40.mExtension;
          v40.mExtension = (IAmdDxExt *)SimpleXML::XMLDocument::GetNode(
                                          xml_doc,
                                          "Parent",
                                          (SimpleXML::XMLNode *)v40.mExtension) )
    {
      result.mStereo = (IAmdDxExtQuadBufferStereo *)SimpleXML::XMLNode::GetValue((SimpleXML::XMLNode *)v40.mExtension);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&v40, (const char *)result.mStereo);
      v4 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v40);
      _((AMD_HD3D *)v4);
      UFG::PropertySetManager::AppendParentLocal(property_set, (const char *)result.mStereo);
      _(&v40);
    }
    if ( text_a && *text_a )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "$inherit", -1) )
      {
        v58 = UFG::qSymbol::create_from_string(&v45, text_a);
        v74 = v58;
        UFG::qPropertySet::SetSchemaName(property_set, v58);
        _((AMD_HD3D *)&v45);
      }
      else
      {
        UFG::qPropertyCollection::SetFlags(property_set, 0x80000);
        result.mExtension = (IAmdDxExt *)UFG::RecursiveSchemaGet(property_set);
        if ( UFG::qSymbol::operator!=((UFG::qSymbol *)result.mExtension, &UFG::gNullQSymbol) )
          UFG::qPropertySet::SetSchemaName(property_set, (UFG::qSymbol *)result.mExtension);
      }
      SchemaName = UFG::qPropertySet::GetSchemaName(property_set);
      if ( UFG::qSymbol::operator!=(SchemaName, &UFG::gNullQSymbol) )
      {
        v6 = UFG::qPropertySet::GetSchemaName(property_set);
        HIDWORD(v40.mStereo) = UFG::PropertySetManager::GetSchema(v6) != 0i64;
        v31 = BYTE4(v40.mStereo);
        sym = UFG::qPropertySet::GetName(property_set);
        v7 = UFG::qPropertySet::GetSchemaName(property_set);
        if ( UFG::qSymbol::operator!=(v7, sym) && !v31 )
          UFG::qPrintf(
            "Warning: schema of name (%s) is not loaded while parsing propertyset (%s)\n",
            text_a,
            pszSymbolString);
        v68 = UFG::qPropertySet::GetName(property_set);
        v8 = UFG::qPropertySet::GetSchemaName(property_set);
        if ( UFG::qSymbol::operator!=(v8, v68) && v31 )
        {
          v9 = UFG::qPropertySet::GetSchemaName(property_set);
          UFG::PropertySetManager::SetupSchemaSet(property_set, v9);
        }
        else
        {
          v32 = 1;
          if ( UFG::qPropertySet::NumParents(property_set) )
          {
            ParentFromIdx = UFG::qPropertySet::GetParentFromIdx(property_set, 0);
            v62 = UFG::qPropertySet::GetName(ParentFromIdx);
            v10 = UFG::qPropertySet::GetSchemaName(ParentFromIdx);
            if ( UFG::qSymbol::operator==(v10, v62) )
            {
              v11 = UFG::qPropertySet::GetSchemaName(ParentFromIdx);
              UFG::PropertySetManager::SetupSchemaSet(property_set, v11);
            }
          }
        }
      }
    }
    UFG::qPropertySet::SetAllPropertiesToDefault(property_set);
    v12 = UFG::qPropertySet::GetSchemaName(property_set);
    if ( UFG::qSymbol::operator==(v12, &UFG::gNullQSymbol) )
      UFG::CreateNeededSchemaSetsFromParentHierarchy(property_set);
  }
  if ( property_set )
    v53 = "Property";
  else
    v53 = "ListProperty";
  *(_QWORD *)&v40.mWidth = v53;
  for ( node = SimpleXML::XMLDocument::GetChildNode(xml_doc, v53, propertyset_node);
        node;
        node = SimpleXML::XMLDocument::GetNode(xml_doc, *(const char **)&v40.mWidth, node) )
  {
    Attribute = (hkSeekableStreamReader *)SimpleXML::XMLNode::GetAttribute(node, "name");
    v49 = SimpleXML::XMLNode::GetAttribute(node, "type");
    UFG::qSymbol::create_from_string(&propertyName, (const char *)Attribute);
    if ( v32 )
      UFG::PropertyMetadataDatabase::LoadFromPropertyNode(&propertyName, node);
    property_set_data = property_set;
    if ( property_set )
    {
      v13 = UFG::qPropertySet::GetSchemaName(property_set);
      if ( UFG::qSymbol::operator!=(v13, &UFG::gNullQSymbol) )
      {
        v72 = UFG::qPropertySet::GetName(property_set);
        v14 = UFG::qPropertySet::GetSchemaName(property_set);
        if ( !UFG::qSymbol::operator==(v14, v72)
          && !UFG::qPropertySet::PropertyExists(property_set, &propertyName, DEPTH_LOCAL) )
        {
          v15 = (UFG::qSymbolUC *)UFG::qPropertySet::GetSchemaName(property_set);
          v16 = UFG::qSymbol::as_cstr_dbg(v15);
          RCX = Assembly::GetRCX(v16);
          Filename = SimpleXML::XMLDocument::GetFilename(xml_doc);
          v70 = Assembly::GetRCX(Filename);
          v18 = Assembly::GetRCX(Attribute);
          UFG::qPrintf(
            "Warning: non-schema property named [%s] found in set [%s] with schema [%s], ignoring\n",
            (const char *)v18,
            (const char *)v70,
            (const char *)RCX);
          _((AMD_HD3D *)&propertyName);
          continue;
        }
      }
      v19 = UFG::qPropertySet::GetSchemaName(property_set);
      if ( UFG::qSymbol::operator==(v19, &UFG::gNullQSymbol) )
      {
        component_schema = UFG::PropertySetManager::GetSchemaForProperty(property_set, &propertyName);
        if ( component_schema )
        {
          if ( component_schema->mbComponentSchema )
          {
            property_set_data = UFG::PropertySetManager::AddComponentPropertySet(property_set, component_schema, 0i64);
          }
          else
          {
            v20 = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(property_set);
            v56 = UFG::qSymbol::as_cstr_dbg(v20);
            v21 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propertyName);
            v22 = Assembly::GetRCX(v21);
            UFG::qPrintf(
              "Warning: found schema property [%s] in non-schema property set [%s]\n",
              (const char *)v22,
              v56);
          }
        }
      }
    }
    v23 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&propertyName);
    _((AMD_HD3D *)v23);
    if ( !UFG::AddBasicPropertyFromNode(
            xml_doc,
            node,
            (UFG::qArray<unsigned long,0> *)&propertyName,
            property_set_data,
            property_list_data) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(v49, "List", -1)
        && (unsigned int)UFG::qStringCompareInsensitive(v49, "WeightedList", -1) )
      {
        if ( !(unsigned int)UFG::qStringCompareInsensitive(v49, "PropSet", -1) )
        {
          ChildNode = SimpleXML::XMLDocument::GetChildNode(xml_doc, "PropertySet", node);
          property_seta = 0i64;
          if ( property_set_data )
            property_seta = UFG::qPropertySet::Get<UFG::qPropertySet>(
                              property_set_data,
                              (UFG::qArray<unsigned long,0> *)&propertyName,
                              DEPTH_LOCAL);
          if ( property_seta )
          {
            UFG::qPrintf(&customCaption);
          }
          else
          {
            v52 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, "qPropertySet");
            if ( v52 )
            {
              UFG::qPropertySet::qPropertySet(v52, &UFG::gNullQSymbol);
              v54 = v25;
            }
            else
            {
              v54 = 0i64;
            }
            v59 = v54;
            property_seta = v54;
          }
          result.mLineOffset = v29;
          v26 = UFG::FromXMLNode(property_seta, 0i64, xml_doc, ChildNode);
          v29 = v26 & result.mLineOffset;
          if ( property_set_data )
          {
            if ( UFG::PropertySetManager::IsComponentPropertySet(property_seta) )
            {
              v27 = UFG::qPropertySet::GetSchemaName(property_seta);
              Schema = UFG::PropertySetManager::GetSchema(v27);
              UFG::PropertySetManager::UpdateDefaultValues(property_seta, property_set_data, &Schema->mPropertyName);
            }
            UFG::qPropertySet::Set<UFG::qPropertySet>(
              property_set_data,
              (UFG::qArray<unsigned long,0> *)&propertyName,
              property_seta);
          }
          if ( property_list_data )
            UFG::qPropertyList::Add<UFG::qPropertySet>(property_list_data, property_seta);
        }
      }
      else
      {
        v = UFG::qPropertyList::Create("List");
        propertyset_nodea = node;
        result.mHeight = v29;
        v24 = UFG::FromXMLNode(0i64, v, xml_doc, node);
        v29 = v24 & result.mHeight;
        if ( property_set_data )
        {
          UFG::qPropertySet::Set<UFG::qPropertyList>(
            property_set_data,
            (UFG::qArray<unsigned long,0> *)&propertyName,
            v);
          if ( UFG::qSymbol::operator==(&propertyName, &sSimObjChildren) )
          {
            StartingPos = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)v);
            for ( index = 0; index < StartingPos; ++index )
            {
              v51 = UFG::qPropertyList::Get<UFG::qPropertySet>(v, index);
              if ( v51 )
                UFG::qPropertySet::SetType(v51, F3_1Pt44_512);
            }
          }
        }
        if ( property_list_data )
          UFG::qPropertyList::Add<UFG::qPropertyList>(property_list_data, v);
      }
    }
    _((AMD_HD3D *)&propertyName);
  }
  *(_QWORD *)&v40.mWidth = "WeightedListProperty";
  for ( i = SimpleXML::XMLDocument::GetChildNode(xml_doc, "WeightedListProperty", propertyset_node);
        i;
        i = SimpleXML::XMLDocument::GetNode(xml_doc, *(const char **)&v40.mWidth, i) )
  {
    v65 = SimpleXML::XMLNode::GetAttribute(i, "type");
    if ( !(unsigned int)UFG::qStringCompareInsensitive(v65, "Symbol", -1) )
    {
      text = SimpleXML::XMLNode::GetAttribute(i, "weight", "1");
      Value = SimpleXML::XMLNode::GetValue(i);
      result.mWidth = UFG::qToUInt32(text, 0);
      UFG::qSymbol::create_from_string((UFG::qSymbol *)&v40.mStereo, Value);
      if ( property_list_data )
      {
        UFG::qPropertyList::Add<UFG::qSymbol>(property_list_data, (UFG::qSymbol *)&v40.mStereo);
        v48 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)property_list_data);
        UFG::qPropertyList::SetWeight(property_list_data, v48 - 1, result.mWidth);
      }
      _((AMD_HD3D *)&v40.mStereo);
    }
  }
  UFG::PostLoadSchemaCreateCheck(property_set, schema_type, skipparentcheck);
  return v29;
}

// File Line: 1818
// RVA: 0x1F9F30
UFG::qPropertySet *__fastcall UFG::qPropertySetResource::LoadSetFromXMLNode(
        SimpleXML::XMLDocument *xml_doc,
        SimpleXML::XMLNode *parent_node,
        UFG::qPropertySet *existing_set,
        bool clearExistingSet)
{
  UFG::qPropertySet *v5; // rax
  UFG::PropertyModificationCallbackSupress v6[4]; // [rsp+30h] [rbp-88h] BYREF
  UFG::qSymbol result; // [rsp+34h] [rbp-84h] BYREF
  UFG::qPropertySet *property_set; // [rsp+38h] [rbp-80h]
  SimpleXML::XMLNode *propertyset_node; // [rsp+40h] [rbp-78h]
  UFG::qPropertySet *v10; // [rsp+48h] [rbp-70h]
  char *pszSymbolString; // [rsp+50h] [rbp-68h]
  UFG::qPropertySet *v12; // [rsp+58h] [rbp-60h]
  UFG::qPropertySet *v13; // [rsp+60h] [rbp-58h]
  UFG::qPropertySetResource *Resource; // [rsp+68h] [rbp-50h]
  UFG::qPropertySet *v15; // [rsp+70h] [rbp-48h]
  UFG::qPropertySet *v16; // [rsp+78h] [rbp-40h]
  UFG::qPropertySet *v17; // [rsp+80h] [rbp-38h]
  UFG::qPropertySet *v18; // [rsp+88h] [rbp-30h]
  __int64 v19; // [rsp+90h] [rbp-28h]
  __int64 v20; // [rsp+98h] [rbp-20h]
  __int64 v21; // [rsp+A0h] [rbp-18h]

  v21 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress(v6);
  propertyset_node = 0i64;
  if ( parent_node )
    propertyset_node = SimpleXML::XMLDocument::GetChildNode(xml_doc, "PropertySet", parent_node);
  else
    propertyset_node = SimpleXML::XMLDocument::GetNode(xml_doc, "PropertySet", 0i64);
  if ( propertyset_node )
  {
    pszSymbolString = SimpleXML::XMLNode::GetAttribute(propertyset_node, "name", &customCaption);
    UFG::qSymbol::create_from_string(&result, pszSymbolString);
    property_set = existing_set;
    if ( !existing_set )
    {
      v13 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, "qPropertySet");
      if ( v13 )
      {
        UFG::qPropertySet::qPropertySet(v13);
        v12 = v5;
      }
      else
      {
        v12 = 0i64;
      }
      v16 = v12;
      property_set = v12;
    }
    if ( UFG::qSymbol::operator!=(&result, &UFG::gNullQSymbol) )
    {
      if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(property_set) )
      {
        Resource = UFG::qPropertySet::GetResource(property_set);
        UFG::qPropertySetResource::Rename(Resource, pszSymbolString);
      }
      else
      {
        UFG::qPropertySet::SetName(property_set, &result);
      }
    }
    if ( clearExistingSet )
    {
      UFG::qPropertySet::RemoveParentsAll(property_set);
      UFG::qPropertySet::RemovePropertiesAllLocal(property_set);
    }
    if ( (unsigned __int8)UFG::FromXMLNode(property_set, 0i64, xml_doc, propertyset_node) == 1 )
    {
      v18 = property_set;
      _((AMD_HD3D *)&result);
      UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(v6);
      return v18;
    }
    else
    {
      if ( !existing_set )
      {
        v15 = property_set;
        v10 = property_set;
        if ( property_set )
          v17 = UFG::qPropertySet::`scalar deleting destructor(v10, 1);
        else
          v17 = 0i64;
      }
      v19 = 0i64;
      _((AMD_HD3D *)&result);
      UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(v6);
      return (UFG::qPropertySet *)v19;
    }
  }
  else
  {
    v20 = 0i64;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress(v6);
    return (UFG::qPropertySet *)v20;
  }
}

