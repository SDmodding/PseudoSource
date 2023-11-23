// File Line: 13
// RVA: 0xD19AC0
void __fastcall hkpRegisterAlternateShapeTypes(hkpCollisionDispatcher *dis)
{
  hkpCollisionDispatcher::registerAlternateShapeType(dis, SPHERE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, TRIANGLE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, BOX, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CAPSULE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CYLINDER, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CONVEX_VERTICES, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CONVEX_TRANSLATE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CONVEX_TRANSFORM, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CONVEX_PIECE, CONVEX);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, TRIANGLE_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, LIST, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, EXTENDED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, COMPRESSED_MESH, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, TRI_SAMPLED_HEIGHT_FIELD_COLLECTION, COLLECTION);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, MOPP, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, STATIC_COMPOUND, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, BV_COMPRESSED_MESH, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, TRI_SAMPLED_HEIGHT_FIELD_BV_TREE, BV_TREE);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, CONVEX, SPHERE_REP);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, PLANE, HEIGHT_FIELD);
  hkpCollisionDispatcher::registerAlternateShapeType(dis, SAMPLED_HEIGHT_FIELD, HEIGHT_FIELD);
}

// File Line: 45
// RVA: 0xD198D0
const char *__fastcall hkGetShapeTypeName(hkcdShapeType::ShapeTypeEnum type)
{
  const char *result; // rax

  switch ( type )
  {
    case ALL_SHAPE_TYPES:
      result = "hkcdShapeType::ALL_SHAPE_TYPES";
      break;
    case SPHERE:
      result = "hkcdShapeType::SPHERE";
      break;
    case CYLINDER:
      result = "hkcdShapeType::CYLINDER";
      break;
    case TRIANGLE:
      result = "hkcdShapeType::TRIANGLE";
      break;
    case BOX:
      result = "hkcdShapeType::BOX";
      break;
    case CAPSULE:
      result = "hkcdShapeType::CAPSULE";
      break;
    case CONVEX_VERTICES:
      result = "hkcdShapeType::CONVEX_VERTICES";
      break;
    case TRI_SAMPLED_HEIGHT_FIELD_COLLECTION:
      result = "hkcdShapeType::TRI_SAMPLED_HEIGHT_FIELD_COLLECTION";
      break;
    case TRI_SAMPLED_HEIGHT_FIELD_BV_TREE:
      result = "hkcdShapeType::TRI_SAMPLED_HEIGHT_FIELD_BV_TREE";
      break;
    case LIST:
      result = "hkcdShapeType::LIST";
      break;
    case MOPP:
      result = "hkcdShapeType::MOPP";
      break;
    case CONVEX_TRANSLATE:
      result = "hkcdShapeType::CONVEX_TRANSLATE";
      break;
    case CONVEX_TRANSFORM:
      result = "hkcdShapeType::CONVEX_TRANSFORM";
      break;
    case SAMPLED_HEIGHT_FIELD:
      result = "hkcdShapeType::SAMPLED_HEIGHT_FIELD";
      break;
    case EXTENDED_MESH:
      result = "hkcdShapeType::EXTENDED_MESH";
      break;
    case TRANSFORM:
      result = "hkcdShapeType::TRANSFORM";
      break;
    case COMPRESSED_MESH:
      result = "hkcdShapeType::COMPRESSED_MESH";
      break;
    case STATIC_COMPOUND:
      result = "hkcdShapeType::STATIC_COMPOUND";
      break;
    case BV_COMPRESSED_MESH:
      result = "hkcdShapeType::BV_COMPRESSED_MESH";
      break;
    case COLLECTION:
      result = "hkcdShapeType::COLLECTION";
      break;
    case USER0:
      result = "hkcdShapeType::USER0";
      break;
    case USER1:
      result = "hkcdShapeType::USER1";
      break;
    case USER2:
      result = "hkcdShapeType::USER2";
      break;
    case BV_TREE:
      result = "hkcdShapeType::BV_TREE";
      break;
    case CONVEX:
      result = "hkcdShapeType::CONVEX";
      break;
    case CONVEX_PIECE:
      result = "hkcdShapeType::CONVEX_PIECE";
      break;
    case MULTI_SPHERE:
      result = "hkcdShapeType::MULTI_SPHERE";
      break;
    case CONVEX_LIST:
      result = "hkcdShapeType::CONVEX_LIST";
      break;
    case TRIANGLE_COLLECTION:
      result = "hkcdShapeType::TRIANGLE_COLLECTION";
      break;
    case HEIGHT_FIELD:
      result = "hkcdShapeType::HEIGHT_FIELD";
      break;
    case SPHERE_REP:
      result = "hkcdShapeType::SPHERE_REP";
      break;
    case BV:
      result = "hkcdShapeType::BV";
      break;
    case PLANE:
      result = "hkcdShapeType::PLANE";
      break;
    case PHANTOM_CALLBACK:
      result = "hkcdShapeType::PHANTOM_CALLBACK";
      break;
    case MULTI_RAY:
      result = "hkcdShapeType::MULTI_RAY";
      break;
    case INVALID:
      result = "hkcdShapeType::INVALID";
      break;
    case MAX_PPU_SHAPE_TYPE:
      result = "hkcdShapeType::MAX_PPU_SHAPE_TYPE";
      break;
    default:
      result = 0i64;
      break;
  }
  return result;
}

