// File Line: 1071
// RVA: 0x1EFD50
char __usercall UFG::AddBasicPropertyFromNode@<al>(SimpleXML::XMLDocument *xml_doc@<rcx>, SimpleXML::XMLNode *property_node@<rdx>, UFG::qSymbol *property_name@<r8>, UFG::qPropertySet *property_set_data@<r9>, int a5@<xmm0>, UFG::qPropertyList *property_list_data)
{
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  const char *v9; // rax
  const char *v10; // rax
  unsigned int v11; // eax
  char v13; // [rsp+20h] [rbp-3C8h]
  const char *text_a; // [rsp+28h] [rbp-3C0h]
  char *text; // [rsp+30h] [rbp-3B8h]
  signed int v16; // [rsp+38h] [rbp-3B0h]
  UFG::qWiseSymbol v17; // [rsp+3Ch] [rbp-3ACh]
  __int16 v18; // [rsp+40h] [rbp-3A8h]
  UFG::qSymbol v19; // [rsp+44h] [rbp-3A4h]
  UFG::qSymbolUC v20; // [rsp+48h] [rbp-3A0h]
  unsigned __int16 v21; // [rsp+4Ch] [rbp-39Ch]
  UFG::qSymbol result; // [rsp+50h] [rbp-398h]
  int v23; // [rsp+54h] [rbp-394h]
  unsigned int v24; // [rsp+58h] [rbp-390h]
  unsigned int v25; // [rsp+5Ch] [rbp-38Ch]
  float v26; // [rsp+60h] [rbp-388h]
  float v27; // [rsp+64h] [rbp-384h]
  float v28; // [rsp+68h] [rbp-380h]
  float v29; // [rsp+6Ch] [rbp-37Ch]
  float v30; // [rsp+70h] [rbp-378h]
  float v31; // [rsp+74h] [rbp-374h]
  float v32; // [rsp+78h] [rbp-370h]
  float v33; // [rsp+80h] [rbp-368h]
  float v34; // [rsp+84h] [rbp-364h]
  float v35; // [rsp+88h] [rbp-360h]
  float v36; // [rsp+90h] [rbp-358h]
  float v37; // [rsp+94h] [rbp-354h]
  float v38; // [rsp+98h] [rbp-350h]
  float v39; // [rsp+A0h] [rbp-348h]
  float v40; // [rsp+A4h] [rbp-344h]
  float v41; // [rsp+A8h] [rbp-340h]
  char *v42; // [rsp+B0h] [rbp-338h]
  float a; // [rsp+B8h] [rbp-330h]
  hkBaseObjectVtbl *v44; // [rsp+BCh] [rbp-32Ch]
  int v45; // [rsp+C4h] [rbp-324h]
  float v46; // [rsp+C8h] [rbp-320h]
  float v47; // [rsp+CCh] [rbp-31Ch]
  float v48; // [rsp+D0h] [rbp-318h]
  float v49; // [rsp+D4h] [rbp-314h]
  float v50; // [rsp+D8h] [rbp-310h]
  float v51; // [rsp+DCh] [rbp-30Ch]
  int v52; // [rsp+E0h] [rbp-308h]
  float v53; // [rsp+E4h] [rbp-304h]
  float v54; // [rsp+E8h] [rbp-300h]
  float v55; // [rsp+ECh] [rbp-2FCh]
  unsigned int v56; // [rsp+F0h] [rbp-2F8h]
  float v57; // [rsp+F4h] [rbp-2F4h]
  float v; // [rsp+F8h] [rbp-2F0h]
  float v59; // [rsp+FCh] [rbp-2ECh]
  float v60; // [rsp+100h] [rbp-2E8h]
  float v61; // [rsp+104h] [rbp-2E4h]
  char *v62; // [rsp+108h] [rbp-2E0h]
  char *v63; // [rsp+110h] [rbp-2D8h]
  hkSeekableStreamReader *v64; // [rsp+118h] [rbp-2D0h]
  char *v65; // [rsp+120h] [rbp-2C8h]
  int v66; // [rsp+128h] [rbp-2C0h]
  int v67; // [rsp+130h] [rbp-2B8h]
  int v68; // [rsp+138h] [rbp-2B0h]
  float v69; // [rsp+140h] [rbp-2A8h]
  float v70; // [rsp+150h] [rbp-298h]
  UFG::qVector2 v71; // [rsp+158h] [rbp-290h]
  float v72; // [rsp+160h] [rbp-288h]
  SimpleXML::XMLNode *v73; // [rsp+168h] [rbp-280h]
  float v74; // [rsp+170h] [rbp-278h]
  SimpleXML::XMLNode *v75; // [rsp+178h] [rbp-270h]
  float v76; // [rsp+180h] [rbp-268h]
  SimpleXML::XMLNode *v77; // [rsp+188h] [rbp-260h]
  float v78; // [rsp+190h] [rbp-258h]
  hkSeekableStreamReader *v79; // [rsp+198h] [rbp-250h]
  float v80; // [rsp+1A0h] [rbp-248h]
  hkSeekableStreamReader *v81; // [rsp+1A8h] [rbp-240h]
  int v82; // [rsp+1B0h] [rbp-238h]
  float v83; // [rsp+1B8h] [rbp-230h]
  float v84; // [rsp+1BCh] [rbp-22Ch]
  float v85; // [rsp+1C0h] [rbp-228h]
  float v86; // [rsp+1C8h] [rbp-220h]
  float v87; // [rsp+1D0h] [rbp-218h]
  float v88; // [rsp+1D8h] [rbp-210h]
  float v89; // [rsp+1E0h] [rbp-208h]
  float v90; // [rsp+1E8h] [rbp-200h]
  float v91; // [rsp+1F0h] [rbp-1F8h]
  float v92; // [rsp+1F8h] [rbp-1F0h]
  float v93; // [rsp+200h] [rbp-1E8h]
  float v94; // [rsp+204h] [rbp-1E4h]
  int v95; // [rsp+208h] [rbp-1E0h]
  float v96; // [rsp+20Ch] [rbp-1DCh]
  int v97; // [rsp+210h] [rbp-1D8h]
  int v98; // [rsp+214h] [rbp-1D4h]
  int v99; // [rsp+220h] [rbp-1C8h]
  int v100; // [rsp+228h] [rbp-1C0h]
  float v101; // [rsp+238h] [rbp-1B0h]
  int v102; // [rsp+240h] [rbp-1A8h]
  int v103; // [rsp+244h] [rbp-1A4h]
  int v104; // [rsp+248h] [rbp-1A0h]
  float v105; // [rsp+250h] [rbp-198h]
  float v106; // [rsp+258h] [rbp-190h]
  float v107; // [rsp+260h] [rbp-188h]
  int v108; // [rsp+268h] [rbp-180h]
  float v109; // [rsp+270h] [rbp-178h]
  unsigned int w; // [rsp+278h] [rbp-170h]
  float v111; // [rsp+280h] [rbp-168h]
  float v112; // [rsp+290h] [rbp-158h]
  float v113; // [rsp+298h] [rbp-150h]
  float v114; // [rsp+2A0h] [rbp-148h]
  int v115; // [rsp+2A8h] [rbp-140h]
  float v116; // [rsp+2B0h] [rbp-138h]
  float v117; // [rsp+2B4h] [rbp-134h]
  float v118; // [rsp+2B8h] [rbp-130h]
  int v119; // [rsp+2BCh] [rbp-12Ch]
  float v120; // [rsp+2C0h] [rbp-128h]
  float v121; // [rsp+2C4h] [rbp-124h]
  float v122; // [rsp+2C8h] [rbp-120h]
  float v123; // [rsp+2D0h] [rbp-118h]
  float v124; // [rsp+2D8h] [rbp-110h]
  float v125; // [rsp+2DCh] [rbp-10Ch]
  float v126; // [rsp+2E0h] [rbp-108h]
  UFG::qVector3 v127; // [rsp+2E8h] [rbp-100h]
  __int64 v128; // [rsp+2F8h] [rbp-F0h]
  char *v129; // [rsp+300h] [rbp-E8h]
  unsigned __int64 v130; // [rsp+308h] [rbp-E0h]
  UFG::qVector4 v131; // [rsp+310h] [rbp-D8h]
  UFG::qRangedValue<long> v132; // [rsp+320h] [rbp-C8h]
  UFG::qTransQuat v133; // [rsp+328h] [rbp-C0h]
  char *v134; // [rsp+348h] [rbp-A0h]
  char *v135; // [rsp+350h] [rbp-98h]
  char *v136; // [rsp+358h] [rbp-90h]
  char *v137; // [rsp+360h] [rbp-88h]
  const char *v138; // [rsp+368h] [rbp-80h]
  char *v139; // [rsp+370h] [rbp-78h]
  char *v140; // [rsp+378h] [rbp-70h]
  char *v141; // [rsp+380h] [rbp-68h]
  char *pszSymbolString; // [rsp+388h] [rbp-60h]
  hkSeekableStreamReader v143; // [rsp+390h] [rbp-58h]
  char v144; // [rsp+3A0h] [rbp-48h]
  float v145; // [rsp+3A4h] [rbp-44h]
  float v146; // [rsp+3A8h] [rbp-40h]
  int v147; // [rsp+3ACh] [rbp-3Ch]
  char v148; // [rsp+3B0h] [rbp-38h]
  float v149; // [rsp+3B4h] [rbp-34h]
  float v150; // [rsp+3B8h] [rbp-30h]
  int v151; // [rsp+3BCh] [rbp-2Ch]
  char v152; // [rsp+3C0h] [rbp-28h]
  int v153; // [rsp+3C4h] [rbp-24h]
  int v154; // [rsp+3C8h] [rbp-20h]
  int v155; // [rsp+3CCh] [rbp-1Ch]
  __int64 v156; // [rsp+3D0h] [rbp-18h]
  SimpleXML::XMLDocument *v157; // [rsp+3F0h] [rbp+8h]
  SimpleXML::XMLNode *prev_node; // [rsp+3F8h] [rbp+10h]
  UFG::qSymbol *name; // [rsp+400h] [rbp+18h]
  UFG::qPropertySet *v160; // [rsp+408h] [rbp+20h]

  v160 = property_set_data;
  name = property_name;
  prev_node = property_node;
  v157 = xml_doc;
  v156 = -2i64;
  text_a = SimpleXML::XMLNode::GetAttribute(property_node, "type");
  text = (char *)SimpleXML::XMLNode::GetValue(prev_node);
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
                                            v136 = SimpleXML::XMLNode::GetAttribute(prev_node, "weight", "1");
                                            v10 = SimpleXML::XMLNode::GetValue(prev_node);
                                            UFG::qSymbol::create_from_string(&v19, v10);
                                            w = UFG::qToInt32(v136, 0);
                                            v140 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&v19);
                                            v11 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v19);
                                            _((AMD_HD3D *)v11);
                                            if ( v160 )
                                              UFG::qPropertySet::Set<UFG::qSymbol>(v160, name, &v19);
                                            if ( property_list_data )
                                            {
                                              UFG::qPropertyList::Add<UFG::qSymbol>(property_list_data, &v19);
                                              v97 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)property_list_data);
                                              UFG::qPropertyList::SetWeight(property_list_data, v97 - 1, w);
                                            }
                                            _((AMD_HD3D *)&v19);
                                          }
                                        }
                                        else
                                        {
                                          v135 = SimpleXML::XMLNode::GetAttribute(prev_node, "range", "100");
                                          v132.mRange = UFG::qToInt32(v135, 0);
                                          v9 = SimpleXML::XMLNode::GetValue(prev_node);
                                          v132.mValue = UFG::qToInt32(v9, 0);
                                          if ( v160 )
                                            UFG::qPropertySet::Set<UFG::qRangedValue<long>>(v160, name, &v132);
                                        }
                                      }
                                      else
                                      {
                                        v73 = SimpleXML::XMLDocument::GetChildNode(v157, "Translation", prev_node);
                                        v75 = SimpleXML::XMLDocument::GetChildNode(v157, "Forward", prev_node);
                                        v77 = SimpleXML::XMLDocument::GetChildNode(v157, "Up", prev_node);
                                        SimpleXML::XMLNode::GetAttribute(v73, "z", 0.0);
                                        v115 = a5;
                                        SimpleXML::XMLNode::GetAttribute(v73, "y", 0.0);
                                        SimpleXML::XMLNode::GetAttribute(v73, "x", 0.0);
                                        v82 = a5;
                                        v102 = a5;
                                        v103 = a5;
                                        v104 = a5;
                                        SimpleXML::XMLNode::GetAttribute(v75, "z", 0.0);
                                        v67 = a5;
                                        SimpleXML::XMLNode::GetAttribute(v75, "y", 0.0);
                                        SimpleXML::XMLNode::GetAttribute(v75, "x", 0.0);
                                        v100 = a5;
                                        v39 = *(float *)&a5;
                                        v40 = *(float *)&a5;
                                        v41 = *(float *)&a5;
                                        SimpleXML::XMLNode::GetAttribute(v77, "z", 0.0);
                                        SimpleXML::XMLNode::GetAttribute(v77, "y", 0.0);
                                        SimpleXML::XMLNode::GetAttribute(v77, "x", 0.0);
                                        v68 = a5;
                                        v33 = *(float *)&a5;
                                        v34 = *(float *)&a5;
                                        v35 = *(float *)&a5;
                                        Assembly::GetRCX(&v143);
                                        a = (float)((float)(v33 * v33) + (float)(v34 * v34)) + (float)(v35 * v35);
                                        if ( a == 0.0 )
                                          v51 = 0.0;
                                        else
                                          v51 = UFG::qRSqrt(a);
                                        v26 = v51;
                                        v109 = v35 * v51;
                                        v107 = v34 * v51;
                                        v105 = v33 * v51;
                                        v59 = v33 * v51;
                                        v60 = v34 * v51;
                                        v61 = v35 * v51;
                                        v53 = (float)((float)(v39 * v39) + (float)(v40 * v40)) + (float)(v41 * v41);
                                        if ( v53 == 0.0 )
                                          v55 = 0.0;
                                        else
                                          v55 = UFG::qRSqrt(v53);
                                        v32 = v55;
                                        v114 = v41 * v55;
                                        v112 = v40 * v55;
                                        v111 = v39 * v55;
                                        v116 = v39 * v55;
                                        v117 = v40 * v55;
                                        v118 = v41 * v55;
                                        v64 = &v143;
                                        v83 = v39 * v55;
                                        v69 = v40 * v55;
                                        v84 = v41 * v55;
                                        *(float *)&v143.vfptr = v39 * v55;
                                        *((float *)&v143.vfptr + 1) = v40 * v55;
                                        *(float *)&v143.m_memSizeAndFlags = v41 * v55;
                                        *(_DWORD *)(&v143.m_referenceCount + 1) = 0;
                                        v79 = &v143;
                                        v70 = v39 * v55;
                                        v86 = v40 * v55;
                                        v72 = v41 * v55;
                                        v46 = v39 * v55;
                                        v47 = v40 * v55;
                                        v48 = v41 * v55;
                                        v90 = (float)(v59 * (float)(v40 * v55)) - (float)(v60 * (float)(v39 * v55));
                                        v74 = (float)(v61 * (float)(v39 * v55)) - (float)(v59 * (float)(v41 * v55));
                                        v88 = (float)(v60 * (float)(v41 * v55)) - (float)(v61 * (float)(v40 * v55));
                                        v36 = (float)(v60 * (float)(v41 * v55)) - (float)(v61 * (float)(v40 * v55));
                                        v37 = (float)(v61 * (float)(v39 * v55)) - (float)(v59 * (float)(v41 * v55));
                                        v38 = (float)(v59 * (float)(v40 * v55)) - (float)(v60 * (float)(v39 * v55));
                                        v57 = (float)((float)(v36 * v36) + (float)(v74 * v37)) + (float)(v90 * v38);
                                        if ( v57 == 0.0 )
                                          v49 = 0.0;
                                        else
                                          v49 = UFG::qRSqrt(v57);
                                        v27 = v49;
                                        v78 = v38 * v49;
                                        v92 = v37 * v49;
                                        v76 = v36 * v49;
                                        v120 = v36 * v49;
                                        v121 = v37 * v49;
                                        v122 = v38 * v49;
                                        v62 = &v144;
                                        v94 = v36 * v49;
                                        v80 = v37 * v49;
                                        v96 = v38 * v49;
                                        *(float *)&v144 = v36 * v49;
                                        v145 = v37 * v49;
                                        v146 = v38 * v49;
                                        v147 = 0;
                                        v81 = &v143;
                                        v98 = HIDWORD(v143.vfptr);
                                        v66 = (int)v143.vfptr;
                                        v99 = *(_DWORD *)&v143.m_memSizeAndFlags;
                                        v44 = v143.vfptr;
                                        v45 = *(_DWORD *)&v143.m_memSizeAndFlags;
                                        v42 = &v144;
                                        v87 = (float)(*(float *)&v143.vfptr * (float)(v37 * v49))
                                            - (float)(*((float *)&v143.vfptr + 1) * (float)(v36 * v49));
                                        v101 = (float)(*(float *)&v143.m_memSizeAndFlags * (float)(v36 * v49))
                                             - (float)(*(float *)&v143.vfptr * (float)(v38 * v49));
                                        v85 = (float)(*((float *)&v143.vfptr + 1) * (float)(v38 * v49))
                                            - (float)(*(float *)&v143.m_memSizeAndFlags * (float)(v37 * v49));
                                        v29 = (float)(*((float *)&v143.vfptr + 1) * (float)(v38 * v49))
                                            - (float)(*(float *)&v143.m_memSizeAndFlags * (float)(v37 * v49));
                                        v30 = (float)(*(float *)&v143.m_memSizeAndFlags * (float)(v36 * v49))
                                            - (float)(*(float *)&v143.vfptr * (float)(v38 * v49));
                                        v31 = (float)(*(float *)&v143.vfptr * (float)(v37 * v49))
                                            - (float)(*((float *)&v143.vfptr + 1) * (float)(v36 * v49));
                                        v54 = (float)((float)(v85 * v85) + (float)(v101 * v101)) + (float)(v87 * v87);
                                        if ( v54 == 0.0 )
                                          v50 = 0.0;
                                        else
                                          v50 = UFG::qRSqrt(v54);
                                        v28 = v50;
                                        v106 = v31 * v50;
                                        v89 = v30 * v50;
                                        v123 = v29 * v50;
                                        v124 = v29 * v50;
                                        v125 = v30 * v50;
                                        v126 = v31 * v50;
                                        v63 = &v148;
                                        v91 = v29 * v50;
                                        v113 = v30 * v50;
                                        v93 = v31 * v50;
                                        *(float *)&v148 = v29 * v50;
                                        v149 = v30 * v50;
                                        v150 = v31 * v50;
                                        v151 = 0;
                                        v65 = &v152;
                                        v108 = v102;
                                        v95 = v103;
                                        v119 = v104;
                                        *(_DWORD *)&v152 = v102;
                                        v153 = v103;
                                        v154 = v104;
                                        v155 = (signed int)FLOAT_1_0;
                                        if ( v160 )
                                          UFG::qPropertySet::Set<UFG::qMatrix44>(v160, name, (UFG::qMatrix44 *)&v143);
                                        if ( property_list_data )
                                          UFG::qPropertyList::Add<UFG::qMatrix44>(
                                            property_list_data,
                                            (UFG::qMatrix44 *)&v143);
                                      }
                                    }
                                    else
                                    {
                                      UFG::qTransQuat::qTransQuat(&v133);
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "tx", 0.0);
                                      LODWORD(v133.mTrans.x) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "ty", 0.0);
                                      LODWORD(v133.mTrans.y) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "tz", 0.0);
                                      LODWORD(v133.mTrans.z) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "rx", 0.0);
                                      LODWORD(v133.mRot.x) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "ry", 0.0);
                                      LODWORD(v133.mRot.y) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "rz", 0.0);
                                      LODWORD(v133.mRot.z) = a5;
                                      SimpleXML::XMLNode::GetAttribute(prev_node, "rw", 0.0);
                                      LODWORD(v133.mRot.w) = a5;
                                      if ( v160 )
                                        UFG::qPropertySet::Set<UFG::qTransQuat>(v160, name, &v133);
                                      if ( property_list_data )
                                        UFG::qPropertyList::Add<UFG::qTransQuat>(property_list_data, &v133);
                                    }
                                  }
                                  else
                                  {
                                    SimpleXML::XMLNode::GetAttribute(prev_node, "x", 0.0);
                                    LODWORD(v131.x) = a5;
                                    SimpleXML::XMLNode::GetAttribute(prev_node, "y", 0.0);
                                    LODWORD(v131.y) = a5;
                                    SimpleXML::XMLNode::GetAttribute(prev_node, "z", 0.0);
                                    LODWORD(v131.z) = a5;
                                    SimpleXML::XMLNode::GetAttribute(prev_node, "w", 0.0);
                                    LODWORD(v131.w) = a5;
                                    if ( v160 )
                                      UFG::qPropertySet::Set<UFG::qVector4>(v160, name, &v131);
                                    if ( property_list_data )
                                      UFG::qPropertyList::Add<UFG::qVector4>(property_list_data, &v131);
                                  }
                                }
                                else
                                {
                                  SimpleXML::XMLNode::GetAttribute(prev_node, "x", 0.0);
                                  LODWORD(v127.x) = a5;
                                  SimpleXML::XMLNode::GetAttribute(prev_node, "y", 0.0);
                                  LODWORD(v127.y) = a5;
                                  SimpleXML::XMLNode::GetAttribute(prev_node, "z", 0.0);
                                  LODWORD(v127.z) = a5;
                                  if ( v160 )
                                    UFG::qPropertySet::Set<UFG::qVector3>(v160, name, &v127);
                                  if ( property_list_data )
                                    UFG::qPropertyList::Add<UFG::qVector3>(property_list_data, &v127);
                                }
                              }
                              else
                              {
                                SimpleXML::XMLNode::GetAttribute(prev_node, "x", 0.0);
                                LODWORD(v71.x) = a5;
                                SimpleXML::XMLNode::GetAttribute(prev_node, "y", 0.0);
                                LODWORD(v71.y) = a5;
                                if ( v160 )
                                  UFG::qPropertySet::Set<UFG::qVector2>(v160, name, &v71);
                                if ( property_list_data )
                                  UFG::qPropertyList::Add<UFG::qVector2>(property_list_data, &v71);
                              }
                            }
                            else
                            {
                              v137 = text;
                              UFG::qWiseSymbol::create_from_string(&v17, text);
                              v138 = UFG::qWiseSymbol::as_cstr_dbg(&v17);
                              v8 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v17);
                              _((AMD_HD3D *)v8);
                              if ( v160 )
                                UFG::qPropertySet::Set<UFG::qWiseSymbol>(v160, name, &v17);
                              if ( property_list_data )
                                UFG::qPropertyList::Add<UFG::qWiseSymbol>(property_list_data, &v17);
                              UFG::qWiseSymbol::~qWiseSymbol(&v17);
                            }
                          }
                          else
                          {
                            v141 = text;
                            UFG::qSymbolUC::create_from_string(&v20, text);
                            v134 = UFG::qSymbol::as_cstr_dbg(&v20);
                            v7 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v20);
                            _((AMD_HD3D *)v7);
                            if ( v160 )
                              UFG::qPropertySet::Set<UFG::qSymbolUC>(v160, name, &v20);
                            if ( property_list_data )
                              UFG::qPropertyList::Add<UFG::qSymbolUC>(property_list_data, &v20);
                            _((AMD_HD3D *)&v20);
                          }
                        }
                        else
                        {
                          pszSymbolString = text;
                          UFG::qSymbol::create_from_string(&result, text);
                          v139 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&result);
                          v6 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&result);
                          _((AMD_HD3D *)v6);
                          if ( v160 )
                            UFG::qPropertySet::Set<UFG::qSymbol>(v160, name, &result);
                          if ( property_list_data )
                            UFG::qPropertyList::Add<UFG::qSymbol>(property_list_data, &result);
                          _((AMD_HD3D *)&result);
                        }
                      }
                      else
                      {
                        v129 = text;
                        if ( v160 )
                          UFG::qPropertySet::Set<char const *>(v160, name, v129);
                        if ( property_list_data )
                          UFG::qPropertyList::Add<char const *>(property_list_data, v129);
                      }
                    }
                    else
                    {
                      v13 = UFG::qToBool(text, 0);
                      if ( v160 )
                        UFG::qPropertySet::Set<bool>(v160, name, v13);
                      if ( property_list_data )
                        UFG::qPropertyList::Add<bool>(property_list_data, v13);
                    }
                  }
                  else
                  {
                    v130 = UFG::qToUInt64(text, 0i64);
                    if ( v160 )
                      UFG::qPropertySet::Set<unsigned __int64>(v160, name, v130);
                    if ( property_list_data )
                      UFG::qPropertyList::Add<unsigned __int64>(property_list_data, v130);
                  }
                }
                else
                {
                  v56 = UFG::qToUInt32(text, 0);
                  if ( v160 )
                    UFG::qPropertySet::Set<unsigned long>(v160, name, v56);
                  if ( property_list_data )
                    UFG::qPropertyList::Add<unsigned long>(property_list_data, v56);
                }
              }
              else
              {
                v25 = UFG::qToUInt32(text, 0);
                if ( v25 > 0xFFFF )
                  v25 = 0xFFFF;
                v21 = v25;
                if ( v160 )
                  UFG::qPropertySet::Set<unsigned short>(v160, name, v21);
                if ( property_list_data )
                  UFG::qPropertyList::Add<unsigned short>(property_list_data, v21);
              }
            }
            else
            {
              v24 = UFG::qToUInt32(text, 0);
              if ( v24 > 0xFF )
                v24 = 255;
              if ( v160 )
                UFG::qPropertySet::Set<unsigned char>(v160, name, v24);
              if ( property_list_data )
                UFG::qPropertyList::Add<unsigned char>(property_list_data, v24);
            }
          }
          else
          {
            v128 = UFG::qToInt64(text, 0i64);
            if ( v160 )
              UFG::qPropertySet::Set<__int64>(v160, name, v128);
            if ( property_list_data )
              UFG::qPropertyList::Add<__int64>(property_list_data, v128);
          }
        }
        else
        {
          v52 = UFG::qToInt32(text, 0);
          if ( v160 )
            UFG::qPropertySet::Set<long>(v160, name, v52);
          if ( property_list_data )
            UFG::qPropertyList::Add<long>(property_list_data, v52);
        }
      }
      else
      {
        v16 = UFG::qToInt32(text, 0);
        if ( v16 >= -32768 )
        {
          if ( v16 > 0x7FFF )
            LOWORD(v16) = 0x7FFF;
        }
        else
        {
          LOWORD(v16) = -32768;
        }
        v18 = v16;
        if ( v160 )
          UFG::qPropertySet::Set<short>(v160, name, v18);
        if ( property_list_data )
          UFG::qPropertyList::Add<short>(property_list_data, v18);
      }
    }
    else
    {
      v23 = UFG::qToInt32(text, 0);
      if ( v23 >= -128 )
      {
        if ( v23 > 127 )
          v23 = 127;
      }
      else
      {
        v23 = -128;
      }
      if ( v160 )
        UFG::qPropertySet::Set<signed char>(v160, name, v23);
      if ( property_list_data )
        UFG::qPropertyList::Add<signed char>(property_list_data, v23);
    }
  }
  else
  {
    v = UFG::qToFloat(text, 0.0);
    if ( v160 )
      UFG::qPropertySet::Set<float>(v160, name, v);
    if ( property_list_data )
      UFG::qPropertyList::Add<float>(property_list_data, v);
  }
  return 1;
}

// File Line: 1311
// RVA: 0x1EFC00
void __fastcall UFG::AddAllSchemaDefs(UFG::qPropertySet *property_set, UFG::qArray<UFG::SchemaDef *,0> *schemas_in_parent)
{
  UFG::qSymbol *v2; // rax
  unsigned int v3; // ST40_4
  UFG::qPropertySet *v4; // ST48_8
  unsigned int i; // [rsp+20h] [rbp-38h]
  unsigned int index; // [rsp+24h] [rbp-34h]
  unsigned int parent_index; // [rsp+28h] [rbp-30h]
  signed int v8; // [rsp+2Ch] [rbp-2Ch]
  unsigned int v9; // [rsp+30h] [rbp-28h]
  unsigned int v10; // [rsp+34h] [rbp-24h]
  UFG::SchemaDef *v11; // [rsp+38h] [rbp-20h]
  UFG::qPropertySet *v12; // [rsp+60h] [rbp+8h]
  UFG::qArray<UFG::SchemaDef *,0> *schemas_in_parenta; // [rsp+68h] [rbp+10h]

  schemas_in_parenta = schemas_in_parent;
  v12 = property_set;
  v9 = UFG::qPropertySet::NumProperties(property_set);
  for ( index = 0; index < v9; ++index )
  {
    v2 = UFG::qPropertySet::GetPropertyNameFromIndex(v12, index);
    v11 = UFG::PropertySetManager::GetSchemaForComponentPropertyName(v2);
    if ( v11 )
    {
      for ( i = 0; i < schemas_in_parenta->size; ++i )
      {
        if ( v11 == schemas_in_parenta->p[i] )
        {
          v8 = i;
          goto LABEL_10;
        }
      }
      v8 = -1;
LABEL_10:
      if ( v8 == -1 )
      {
        v3 = schemas_in_parenta->size;
        UFG::qArray<UFG::SchemaDef *,0>::Grow(schemas_in_parenta, 1u, "qArray.Add");
        schemas_in_parenta->p[v3] = v11;
      }
    }
  }
  v10 = UFG::qPropertySet::NumParents(v12);
  for ( parent_index = 0; parent_index < v10; ++parent_index )
  {
    v4 = UFG::qPropertySet::GetParentFromIdx(v12, parent_index);
    UFG::AddAllSchemaDefs(v4, schemas_in_parenta);
  }
}

// File Line: 1335
// RVA: 0x1F41B0
void __fastcall UFG::CreateNeededSchemaSetsFromParentHierarchy(UFG::qPropertySet *property_set)
{
  UFG::qSymbol *v1; // rax
  UFG::qSymbol *v2; // rax
  unsigned int j; // [rsp+20h] [rbp-E8h]
  unsigned int index; // [rsp+24h] [rbp-E4h]
  unsigned int m; // [rsp+28h] [rbp-E0h]
  unsigned int k; // [rsp+2Ch] [rbp-DCh]
  unsigned int l; // [rsp+30h] [rbp-D8h]
  unsigned int n; // [rsp+34h] [rbp-D4h]
  UFG::qArray<UFG::SchemaDef *,0> v9; // [rsp+38h] [rbp-D0h]
  unsigned int parent_index; // [rsp+48h] [rbp-C0h]
  unsigned int i; // [rsp+4Ch] [rbp-BCh]
  unsigned int v12; // [rsp+50h] [rbp-B8h]
  unsigned int v13; // [rsp+54h] [rbp-B4h]
  unsigned int v14; // [rsp+58h] [rbp-B0h]
  UFG::qPropertySet *property_seta; // [rsp+60h] [rbp-A8h]
  UFG::qArray<UFG::SchemaDef *,0> schemas_in_parent; // [rsp+68h] [rbp-A0h]
  UFG::qArray<UFG::SchemaDef *,0> v17; // [rsp+78h] [rbp-90h]
  unsigned int v18; // [rsp+88h] [rbp-80h]
  unsigned int v19; // [rsp+8Ch] [rbp-7Ch]
  unsigned int v20; // [rsp+90h] [rbp-78h]
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
  UFG::qPropertySet *v32; // [rsp+E0h] [rbp-28h]
  UFG::SchemaDef **v33; // [rsp+E8h] [rbp-20h]
  UFG::SchemaDef **v34; // [rsp+F0h] [rbp-18h]
  __int64 v35; // [rsp+F8h] [rbp-10h]
  UFG::qPropertySet *v36; // [rsp+110h] [rbp+8h]

  v36 = property_set;
  v35 = -2i64;
  for ( parent_index = UFG::qPropertySet::NumParents(property_set) - 1; (parent_index & 0x80000000) == 0; --parent_index )
  {
    property_seta = UFG::qPropertySet::GetParentFromIdx(v36, parent_index);
    if ( UFG::PropertySetManager::IsComponentPropertySet(property_seta) )
    {
      v1 = UFG::qPropertySet::GetSchemaName(property_seta);
      component_schema = UFG::PropertySetManager::GetSchema(v1);
      UFG::PropertySetManager::AddComponentPropertySet(v36, component_schema, property_seta);
      v2 = UFG::qPropertySet::GetName(property_seta);
      UFG::qPropertySet::RemoveParent(v36, v2);
    }
  }
  v17.p = 0i64;
  v17.size = 0;
  v17.capacity = 0;
  v9.p = 0i64;
  v9.size = 0;
  v9.capacity = 0;
  v12 = UFG::qPropertySet::NumParents(v36);
  for ( i = 0; i < v12; ++i )
  {
    v32 = UFG::qPropertySet::GetParentFromIdx(v36, i);
    schemas_in_parent.p = 0i64;
    schemas_in_parent.size = 0;
    schemas_in_parent.capacity = 0;
    UFG::AddAllSchemaDefs(v32, &schemas_in_parent);
    for ( j = 0; ; ++j )
    {
      v20 = schemas_in_parent.size;
      if ( j >= schemas_in_parent.size )
        break;
      v34 = &schemas_in_parent.p[j];
      for ( k = 0; k < v17.size; ++k )
      {
        if ( *v34 == v17.p[k] )
        {
          v14 = k;
          goto LABEL_16;
        }
      }
      v14 = -1;
LABEL_16:
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
        for ( l = 0; l < v9.size; ++l )
        {
          if ( *v31 == v9.p[l] )
          {
            v13 = l;
            goto LABEL_24;
          }
        }
        v13 = -1;
LABEL_24:
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
      for ( m = index + 1; ; ++m )
      {
        v18 = v9.size;
        if ( m >= v9.size )
          break;
        v29 = &v9.p[index];
        v30 = &v9.p[m];
        if ( UFG::SchemaDef::IsDerivedFrom(v9.p[m], v9.p[index]) )
        {
          UFG::qArray<UFG::SchemaDef *,0>::StableDelete(&v9, index);
        }
        else
        {
          v26 = &v9.p[m];
          v27 = &v9.p[index];
          if ( UFG::SchemaDef::IsDerivedFrom(v9.p[index], v9.p[m]) )
            UFG::qArray<UFG::SchemaDef *,0>::StableDelete(&v9, m);
        }
      }
    }
    for ( n = 0; ; ++n )
    {
      v21 = v9.size;
      if ( n >= v9.size )
        break;
      UFG::PropertySetManager::AddComponentPropertySet(v36, v9.p[n], 0i64);
    }
  }
  UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&v9);
  UFG::qArray<UFG::PropertyLookup,0>::Clear((UFG::qArray<UFG::PropertyLookup,0> *)&v17);
}

// File Line: 1409
// RVA: 0x1FA580
void __fastcall UFG::PostLoadSchemaCreateCheck(UFG::qPropertySet *property_set, const char *schema_type, const char *skipparentcheck)
{
  UFG::qSymbol *v3; // rax
  UFG::qSymbol *sym; // ST38_8
  UFG::qSymbol *v5; // rax
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::SchemaDef *v8; // [rsp+20h] [rbp-38h]
  UFG::qPropertySet *v9; // [rsp+28h] [rbp-30h]
  UFG::SchemaDef *v10; // [rsp+30h] [rbp-28h]
  UFG::qPropertySet *property_seta; // [rsp+60h] [rbp+8h]
  char *text_a; // [rsp+68h] [rbp+10h]
  char *text; // [rsp+70h] [rbp+18h]

  text = (char *)skipparentcheck;
  text_a = (char *)schema_type;
  property_seta = property_set;
  if ( property_set )
  {
    v3 = UFG::qPropertySet::GetSchemaName(property_set);
    if ( UFG::qSymbol::operator!=(v3, &UFG::gNullQSymbol) )
    {
      sym = UFG::qPropertySet::GetName(property_seta);
      v5 = UFG::qPropertySet::GetSchemaName(property_seta);
      if ( UFG::qSymbol::operator==(v5, sym) )
      {
        v9 = UFG::PropertySetManager::GetParentSchemaSet(property_seta);
        if ( v9 )
        {
          v6 = UFG::qPropertySet::GetName(v9);
          v10 = UFG::PropertySetManager::GetSchema(v6);
        }
        else
        {
          v10 = 0i64;
        }
        v7 = UFG::qPropertySet::GetName(property_seta);
        UFG::PropertySetManager::GetSchema(v7);
        v8 = UFG::PropertySetManager::AddSchemaDef(property_seta, v10);
        if ( text_a && *text_a )
        {
          if ( !(unsigned int)UFG::qStringCompareInsensitive(text_a, "component", -1) )
          {
            UFG::SchemaDef::SetComponentSchema(v8, 1);
            UFG::qPropertyCollection::SetFlags((UFG::qPropertyCollection *)&property_seta->mFlags, 0x100000);
          }
        }
        else if ( (unsigned int)UFG::qPropertyCollection::GetFlags(
                                  (UFG::qPropertyCollection *)&property_seta->mFlags,
                                  0x100000) )
        {
          UFG::SchemaDef::SetComponentSchema(v8, 1);
        }
        if ( text && *text )
        {
          if ( UFG::qToBool(text, 0) == 1 )
          {
            UFG::SchemaDef::SetSkipParentCheck(v8, 1);
            UFG::qPropertyCollection::SetFlags((UFG::qPropertyCollection *)&property_seta->mFlags, 0x200000);
          }
        }
        else if ( (unsigned int)UFG::qPropertyCollection::GetFlags(
                                  (UFG::qPropertyCollection *)&property_seta->mFlags,
                                  0x200000) )
        {
          UFG::SchemaDef::SetSkipParentCheck(v8, 1);
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
  return atexit(UFG::_dynamic_atexit_destructor_for__sSimObjChildren__);
}

// File Line: 1473
// RVA: 0x1F5940
__int64 __usercall UFG::FromXMLNode@<rax>(UFG::qPropertySet *property_set@<rcx>, UFG::qPropertyList *property_list_data@<rdx>, SimpleXML::XMLDocument *xml_doc@<r8>, SimpleXML::XMLNode *propertyset_node@<r9>, int a5@<xmm0>)
{
  unsigned int v5; // eax
  UFG::qSymbol *v6; // rax
  UFG::qSymbol *v7; // rax
  UFG::qSymbol *v8; // rax
  UFG::qSymbol *v9; // rax
  UFG::qSymbol *v10; // rax
  UFG::qSymbol *v11; // rax
  UFG::qSymbol *v12; // rax
  UFG::qSymbol *v13; // rax
  UFG::qSymbol *v14; // rax
  UFG::qSymbol *v15; // rax
  UFG::qSymbolUC *v16; // rax
  char *v17; // rax
  char *v18; // rax
  hkSeekableStreamReader *v19; // rax
  UFG::qSymbol *v20; // rax
  UFG::qSymbolUC *v21; // rax
  char *v22; // rax
  hkSeekableStreamReader *v23; // rax
  unsigned int v24; // eax
  UFG::allocator::free_link *v25; // rax
  char v26; // al
  UFG::qPropertySet *v27; // rax
  char v28; // al
  UFG::qSymbol *v29; // rax
  UFG::qPropertyList *property_list_dataa; // [rsp+20h] [rbp-1A8h]
  unsigned __int8 v32; // [rsp+30h] [rbp-198h]
  UFG::qSymbol propertyName; // [rsp+34h] [rbp-194h]
  bool v34; // [rsp+38h] [rbp-190h]
  char v35; // [rsp+39h] [rbp-18Fh]
  SimpleXML::XMLNode *node; // [rsp+40h] [rbp-188h]
  UFG::qPropertySet *property_seta; // [rsp+48h] [rbp-180h]
  UFG::qPropertySet *property_set_data; // [rsp+50h] [rbp-178h]
  unsigned int index; // [rsp+58h] [rbp-170h]
  SimpleXML::XMLNode *j; // [rsp+60h] [rbp-168h]
  char *text_a; // [rsp+68h] [rbp-160h]
  UFG::qPropertyList *v; // [rsp+70h] [rbp-158h]
  UFG::qSymbol v43; // [rsp+78h] [rbp-150h]
  char *v44; // [rsp+80h] [rbp-148h]
  UFG::qSymbol v45; // [rsp+88h] [rbp-140h]
  BOOL v46; // [rsp+8Ch] [rbp-13Ch]
  SimpleXML::XMLNode *i; // [rsp+90h] [rbp-138h]
  char *pszSymbolString; // [rsp+98h] [rbp-130h]
  UFG::SchemaDef *component_schema; // [rsp+A0h] [rbp-128h]
  UFG::qPropertySet *v50; // [rsp+A8h] [rbp-120h]
  unsigned int v51; // [rsp+B0h] [rbp-118h]
  UFG::qSymbol v52; // [rsp+B4h] [rbp-114h]
  unsigned int v53; // [rsp+B8h] [rbp-110h]
  hkSeekableStreamReader *v54; // [rsp+C0h] [rbp-108h]
  int v55; // [rsp+C8h] [rbp-100h]
  char *v56; // [rsp+D0h] [rbp-F8h]
  UFG::qSymbol result; // [rsp+D8h] [rbp-F0h]
  int v58; // [rsp+DCh] [rbp-ECh]
  unsigned int w; // [rsp+E0h] [rbp-E8h]
  int v60; // [rsp+E4h] [rbp-E4h]
  char *parentNameString; // [rsp+E8h] [rbp-E0h]
  UFG::qSymbol *v62; // [rsp+F0h] [rbp-D8h]
  UFG::qPropertySet *v63; // [rsp+F8h] [rbp-D0h]
  UFG::qPropertySet *v64; // [rsp+100h] [rbp-C8h]
  char *v65; // [rsp+108h] [rbp-C0h]
  UFG::qPropertySet *v66; // [rsp+110h] [rbp-B8h]
  UFG::qSymbol *name; // [rsp+118h] [rbp-B0h]
  char *v68; // [rsp+120h] [rbp-A8h]
  SimpleXML::XMLNode *propertyset_nodea; // [rsp+128h] [rbp-A0h]
  UFG::qSymbol *v70; // [rsp+130h] [rbp-98h]
  UFG::qPropertySet *v71; // [rsp+138h] [rbp-90h]
  UFG::qSymbol *sym; // [rsp+140h] [rbp-88h]
  SimpleXML::XMLNode *v73; // [rsp+148h] [rbp-80h]
  UFG::qSymbol *v74; // [rsp+150h] [rbp-78h]
  UFG::SchemaDef *v75; // [rsp+158h] [rbp-70h]
  hkSeekableStreamReader *v76; // [rsp+160h] [rbp-68h]
  char *v77; // [rsp+168h] [rbp-60h]
  UFG::qSymbol *v78; // [rsp+170h] [rbp-58h]
  char *text; // [rsp+178h] [rbp-50h]
  UFG::qSymbol *v80; // [rsp+180h] [rbp-48h]
  char *v81; // [rsp+188h] [rbp-40h]
  hkSeekableStreamReader *v82; // [rsp+190h] [rbp-38h]
  char *skipparentcheck; // [rsp+198h] [rbp-30h]
  UFG::qSymbol *v84; // [rsp+1A0h] [rbp-28h]
  char *schema_type; // [rsp+1A8h] [rbp-20h]
  UFG::qSymbol *v86; // [rsp+1B0h] [rbp-18h]
  __int64 v87; // [rsp+1B8h] [rbp-10h]
  UFG::qPropertySet *propertySet; // [rsp+1D0h] [rbp+8h]
  UFG::qPropertyList *v89; // [rsp+1D8h] [rbp+10h]
  SimpleXML::XMLDocument *xml_doca; // [rsp+1E0h] [rbp+18h]
  SimpleXML::XMLNode *prev_node; // [rsp+1E8h] [rbp+20h]

  prev_node = propertyset_node;
  xml_doca = xml_doc;
  v89 = property_list_data;
  propertySet = property_set;
  v87 = -2i64;
  v32 = 1;
  pszSymbolString = SimpleXML::XMLNode::GetAttribute(propertyset_node, "name");
  text_a = SimpleXML::XMLNode::GetAttribute(prev_node, "schema");
  schema_type = SimpleXML::XMLNode::GetAttribute(prev_node, "schematype");
  skipparentcheck = SimpleXML::XMLNode::GetAttribute(prev_node, "skipparentcheck");
  v35 = 0;
  if ( propertySet )
  {
    if ( pszSymbolString && *pszSymbolString )
    {
      v78 = UFG::qSymbol::create_from_string(&result, pszSymbolString);
      name = v78;
      UFG::qPropertySet::SetName(propertySet, v78);
      _((AMD_HD3D *)&result);
    }
    for ( i = SimpleXML::XMLDocument::GetChildNode(xml_doca, "Parent", prev_node);
          i;
          i = SimpleXML::XMLDocument::GetNode(xml_doca, "Parent", i) )
    {
      parentNameString = (char *)SimpleXML::XMLNode::GetValue(i);
      UFG::qSymbol::create_from_string(&v43, parentNameString);
      v5 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&v43);
      _((AMD_HD3D *)v5);
      UFG::PropertySetManager::AppendParentLocal(propertySet, parentNameString);
      _((AMD_HD3D *)&v43);
    }
    if ( text_a && *text_a )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(text_a, "$inherit", -1) )
      {
        v70 = UFG::qSymbol::create_from_string(&v52, text_a);
        v86 = v70;
        UFG::qPropertySet::SetSchemaName(propertySet, v70);
        _((AMD_HD3D *)&v52);
      }
      else
      {
        UFG::qPropertyCollection::SetFlags((UFG::qPropertyCollection *)&propertySet->mFlags, 0x80000);
        v62 = UFG::RecursiveSchemaGet(propertySet);
        if ( UFG::qSymbol::operator!=(v62, &UFG::gNullQSymbol) )
          UFG::qPropertySet::SetSchemaName(propertySet, v62);
      }
      v6 = UFG::qPropertySet::GetSchemaName(propertySet);
      if ( UFG::qSymbol::operator!=(v6, &UFG::gNullQSymbol) )
      {
        v7 = UFG::qPropertySet::GetSchemaName(propertySet);
        v46 = UFG::PropertySetManager::GetSchema(v7) != 0i64;
        v34 = v46;
        sym = UFG::qPropertySet::GetName(propertySet);
        v8 = UFG::qPropertySet::GetSchemaName(propertySet);
        if ( UFG::qSymbol::operator!=(v8, sym) && !v34 )
          UFG::qPrintf(
            "Warning: schema of name (%s) is not loaded while parsing propertyset (%s)\n",
            text_a,
            pszSymbolString);
        v80 = UFG::qPropertySet::GetName(propertySet);
        v9 = UFG::qPropertySet::GetSchemaName(propertySet);
        if ( UFG::qSymbol::operator!=(v9, v80) && v34 )
        {
          v10 = UFG::qPropertySet::GetSchemaName(propertySet);
          UFG::PropertySetManager::SetupSchemaSet(propertySet, v10);
        }
        else
        {
          v35 = 1;
          v51 = UFG::qPropertySet::NumParents(propertySet);
          if ( v51 )
          {
            v50 = UFG::qPropertySet::GetParentFromIdx(propertySet, 0);
            v74 = UFG::qPropertySet::GetName(v50);
            v11 = UFG::qPropertySet::GetSchemaName(v50);
            if ( UFG::qSymbol::operator==(v11, v74) )
            {
              v12 = UFG::qPropertySet::GetSchemaName(v50);
              UFG::PropertySetManager::SetupSchemaSet(propertySet, v12);
            }
          }
        }
      }
    }
    UFG::qPropertySet::SetAllPropertiesToDefault(propertySet);
    v13 = UFG::qPropertySet::GetSchemaName(propertySet);
    if ( UFG::qSymbol::operator==(v13, &UFG::gNullQSymbol) )
      UFG::CreateNeededSchemaSetsFromParentHierarchy(propertySet);
  }
  if ( propertySet )
    v65 = "Property";
  else
    v65 = "ListProperty";
  v44 = v65;
  for ( node = SimpleXML::XMLDocument::GetChildNode(xml_doca, v65, prev_node);
        node;
        node = SimpleXML::XMLDocument::GetNode(xml_doca, v44, node) )
  {
    v54 = (hkSeekableStreamReader *)SimpleXML::XMLNode::GetAttribute(node, "name");
    v56 = SimpleXML::XMLNode::GetAttribute(node, "type");
    UFG::qSymbol::create_from_string(&propertyName, (const char *)v54);
    if ( v35 )
      UFG::PropertyMetadataDatabase::LoadFromPropertyNode(&propertyName, node);
    property_set_data = propertySet;
    if ( propertySet )
    {
      v14 = UFG::qPropertySet::GetSchemaName(propertySet);
      if ( UFG::qSymbol::operator!=(v14, &UFG::gNullQSymbol) )
      {
        v84 = UFG::qPropertySet::GetName(propertySet);
        v15 = UFG::qPropertySet::GetSchemaName(propertySet);
        if ( !UFG::qSymbol::operator==(v15, v84) && !UFG::qPropertySet::PropertyExists(propertySet, &propertyName, 0) )
        {
          v16 = (UFG::qSymbolUC *)UFG::qPropertySet::GetSchemaName(propertySet);
          v17 = UFG::qSymbol::as_cstr_dbg(v16);
          v76 = Assembly::GetRCX(v17);
          v18 = SimpleXML::XMLDocument::GetFilename(xml_doca);
          v82 = Assembly::GetRCX(v18);
          v19 = Assembly::GetRCX(v54);
          UFG::qPrintf(
            "Warning: non-schema property named [%s] found in set [%s] with schema [%s], ignoring\n",
            v19,
            v82,
            v76,
            property_list_dataa);
          _((AMD_HD3D *)&propertyName);
          continue;
        }
      }
      v20 = UFG::qPropertySet::GetSchemaName(propertySet);
      if ( UFG::qSymbol::operator==(v20, &UFG::gNullQSymbol) )
      {
        component_schema = UFG::PropertySetManager::GetSchemaForProperty(propertySet, &propertyName);
        if ( component_schema )
        {
          if ( component_schema->mbComponentSchema )
          {
            property_set_data = UFG::PropertySetManager::AddComponentPropertySet(propertySet, component_schema, 0i64);
          }
          else
          {
            v21 = (UFG::qSymbolUC *)UFG::qPropertySet::GetName(propertySet);
            v68 = UFG::qSymbol::as_cstr_dbg(v21);
            v22 = UFG::qSymbol::as_cstr_dbg((UFG::qSymbolUC *)&propertyName);
            v23 = Assembly::GetRCX(v22);
            UFG::qPrintf("Warning: found schema property [%s] in non-schema property set [%s]\n", v23, v68);
          }
        }
      }
    }
    v24 = UFG::qSymbolUC::as_uint32((UFG::qArray<unsigned long,0> *)&propertyName);
    _((AMD_HD3D *)v24);
    if ( !UFG::AddBasicPropertyFromNode(xml_doca, node, &propertyName, property_set_data, a5, v89) )
    {
      if ( (unsigned int)UFG::qStringCompareInsensitive(v56, "List", -1)
        && (unsigned int)UFG::qStringCompareInsensitive(v56, "WeightedList", -1) )
      {
        if ( !(unsigned int)UFG::qStringCompareInsensitive(v56, "PropSet", -1) )
        {
          v73 = SimpleXML::XMLDocument::GetChildNode(xml_doca, "PropertySet", node);
          property_seta = 0i64;
          if ( property_set_data )
            property_seta = UFG::qPropertySet::Get<UFG::qPropertySet>(property_set_data, &propertyName, 0);
          if ( property_seta )
          {
            UFG::qPrintf(&customWorldMapCaption);
          }
          else
          {
            v64 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, "qPropertySet");
            if ( v64 )
            {
              UFG::qPropertySet::qPropertySet(v64, &UFG::gNullQSymbol);
              v66 = v27;
            }
            else
            {
              v66 = 0i64;
            }
            v71 = v66;
            property_seta = v66;
          }
          v58 = v32;
          property_list_dataa = (UFG::qPropertyList *)propertySet;
          v28 = UFG::FromXMLNode(property_seta, 0i64, xml_doca, v73);
          v32 = v28 & v58;
          if ( property_set_data )
          {
            if ( UFG::PropertySetManager::IsComponentPropertySet(property_seta) )
            {
              v29 = UFG::qPropertySet::GetSchemaName(property_seta);
              v75 = UFG::PropertySetManager::GetSchema(v29);
              UFG::PropertySetManager::UpdateDefaultValues(property_seta, property_set_data, &v75->mPropertyName);
            }
            UFG::qPropertySet::Set<UFG::qPropertySet>(property_set_data, &propertyName, property_seta);
          }
          if ( v89 )
            UFG::qPropertyList::Add<UFG::qPropertySet>(v89, property_seta);
        }
      }
      else
      {
        v25 = UFG::qPropertyList::Create("List");
        v = (UFG::qPropertyList *)v25;
        propertyset_nodea = node;
        v60 = v32;
        property_list_dataa = (UFG::qPropertyList *)propertySet;
        v26 = UFG::FromXMLNode(0i64, (UFG::qPropertyList *)v25, xml_doca, node);
        v32 = v26 & v60;
        if ( property_set_data )
        {
          UFG::qPropertySet::Set<UFG::qPropertyList>(property_set_data, &propertyName, v);
          if ( UFG::qSymbol::operator==(&propertyName, (UFG::qSymbol *)&sSimObjChildren.mUID) )
          {
            v53 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)v);
            for ( index = 0; index < v53; ++index )
            {
              v63 = UFG::qPropertyList::Get<UFG::qPropertySet>(v, index);
              if ( v63 )
                UFG::qPropertySet::SetType(v63, F3_1Pt44_512);
            }
          }
        }
        if ( v89 )
          UFG::qPropertyList::Add<UFG::qPropertyList>(v89, v);
      }
    }
    _((AMD_HD3D *)&propertyName);
  }
  v44 = "WeightedListProperty";
  for ( j = SimpleXML::XMLDocument::GetChildNode(xml_doca, "WeightedListProperty", prev_node);
        j;
        j = SimpleXML::XMLDocument::GetNode(xml_doca, v44, j) )
  {
    v77 = SimpleXML::XMLNode::GetAttribute(j, "type");
    if ( !(unsigned int)UFG::qStringCompareInsensitive(v77, "Symbol", -1) )
    {
      text = SimpleXML::XMLNode::GetAttribute(j, "weight", "1");
      v81 = (char *)SimpleXML::XMLNode::GetValue(j);
      w = UFG::qToUInt32(text, 0);
      UFG::qSymbol::create_from_string(&v45, v81);
      if ( v89 )
      {
        UFG::qPropertyList::Add<UFG::qSymbol>(v89, &v45);
        v55 = Scaleform::Render::ShapeDataPacked<Scaleform::ArrayDH<unsigned char,2,Scaleform::ArrayDefaultPolicy>>::GetStartingPos((hkMemoryResourceContainer *)v89);
        UFG::qPropertyList::SetWeight(v89, v55 - 1, w);
      }
      _((AMD_HD3D *)&v45);
    }
  }
  UFG::PostLoadSchemaCreateCheck(propertySet, schema_type, skipparentcheck);
  return v32;
}

// File Line: 1818
// RVA: 0x1F9F30
UFG::qPropertySet *__usercall UFG::qPropertySetResource::LoadSetFromXMLNode@<rax>(SimpleXML::XMLDocument *xml_doc@<rcx>, SimpleXML::XMLNode *parent_node@<rdx>, UFG::qPropertySet *existing_set@<r8>, bool clearExistingSet@<r9b>, int a5@<xmm0>)
{
  UFG::qPropertySet *v5; // rax
  UFG::qPropertySet *v6; // rax
  char v7; // [rsp+30h] [rbp-88h]
  UFG::qSymbol result; // [rsp+34h] [rbp-84h]
  UFG::qPropertySet *property_set; // [rsp+38h] [rbp-80h]
  SimpleXML::XMLNode *propertyset_node; // [rsp+40h] [rbp-78h]
  UFG::qPropertySet *v11; // [rsp+48h] [rbp-70h]
  char *pszSymbolString; // [rsp+50h] [rbp-68h]
  UFG::qPropertySet *v13; // [rsp+58h] [rbp-60h]
  UFG::qPropertySet *v14; // [rsp+60h] [rbp-58h]
  UFG::qPropertySetResource *v15; // [rsp+68h] [rbp-50h]
  UFG::qPropertySet *v16; // [rsp+70h] [rbp-48h]
  UFG::qPropertySet *v17; // [rsp+78h] [rbp-40h]
  UFG::qPropertySet *v18; // [rsp+80h] [rbp-38h]
  UFG::qPropertySet *v19; // [rsp+88h] [rbp-30h]
  UFG::qPropertySet *v20; // [rsp+90h] [rbp-28h]
  UFG::qPropertySet *v21; // [rsp+98h] [rbp-20h]
  __int64 v22; // [rsp+A0h] [rbp-18h]
  SimpleXML::XMLDocument *xml_doca; // [rsp+C0h] [rbp+8h]
  SimpleXML::XMLNode *prev_node; // [rsp+C8h] [rbp+10h]
  UFG::qPropertySet *v25; // [rsp+D0h] [rbp+18h]
  bool v26; // [rsp+D8h] [rbp+20h]

  v26 = clearExistingSet;
  v25 = existing_set;
  prev_node = parent_node;
  xml_doca = xml_doc;
  v22 = -2i64;
  UFG::PropertyModificationCallbackSupress::PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
  propertyset_node = 0i64;
  if ( prev_node )
    propertyset_node = SimpleXML::XMLDocument::GetChildNode(xml_doca, "PropertySet", prev_node);
  else
    propertyset_node = SimpleXML::XMLDocument::GetNode(xml_doca, "PropertySet", 0i64);
  if ( propertyset_node )
  {
    pszSymbolString = SimpleXML::XMLNode::GetAttribute(propertyset_node, "name", &customWorldMapCaption);
    UFG::qSymbol::create_from_string(&result, pszSymbolString);
    property_set = v25;
    if ( !v25 )
    {
      v14 = (UFG::qPropertySet *)UFG::qPropertySet::operator new(0x58ui64, "qPropertySet");
      if ( v14 )
      {
        UFG::qPropertySet::qPropertySet(v14);
        v13 = v6;
      }
      else
      {
        v13 = 0i64;
      }
      v17 = v13;
      property_set = v13;
    }
    if ( UFG::qSymbol::operator!=(&result, &UFG::gNullQSymbol) )
    {
      if ( (unsigned __int8)UFG::qPropertySet::IsResourceSet(property_set) )
      {
        v15 = UFG::qPropertySet::GetResource(property_set);
        UFG::qPropertySetResource::Rename(v15, pszSymbolString);
      }
      else
      {
        UFG::qPropertySet::SetName(property_set, &result);
      }
    }
    if ( v26 )
    {
      UFG::qPropertySet::RemoveParentsAll(property_set);
      UFG::qPropertySet::RemovePropertiesAllLocal(property_set);
    }
    if ( (unsigned __int8)UFG::FromXMLNode(property_set, 0i64, xml_doca, propertyset_node, a5) == 1 )
    {
      v19 = property_set;
      _((AMD_HD3D *)&result);
      UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
      v5 = v19;
    }
    else
    {
      if ( !v25 )
      {
        v16 = property_set;
        v11 = property_set;
        if ( property_set )
          v18 = UFG::qPropertySet::`scalar deleting destructor(v11, 1);
        else
          v18 = 0i64;
      }
      v20 = 0i64;
      _((AMD_HD3D *)&result);
      UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
      v5 = v20;
    }
  }
  else
  {
    v21 = 0i64;
    UFG::PropertyModificationCallbackSupress::~PropertyModificationCallbackSupress((UFG::PropertyModificationCallbackSupress *)&v7);
    v5 = v21;
  }
  return v5;
}

