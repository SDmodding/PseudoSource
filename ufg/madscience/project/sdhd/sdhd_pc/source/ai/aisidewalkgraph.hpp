// File Line: 214
// RVA: 0x4163E0
void __fastcall UFG::AISidewalkGraph::SetAIGraphDirectory(UFG::qString *directory)
{
  UFG::qString::Set(&UFG::AISidewalkGraph::sAIGraphDirectory, directory->mData, directory->mLength, 0i64, 0);
}

