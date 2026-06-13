// Audiobook derives publicly from Track (declared in Track.h) and represents
// an audiobook with an author, synopsis, and page count.
//
// Constructor: initializes the inherited Track fields (title, release,
// duration, size, format) plus author, synopsis, and pageCount.
//
// clone(): returns a polymorphic copy of this Audiobook (Prototype pattern).
//
// toString(): must throw NotImplementedException() rather than returning
// a description. This is the hierarchy's designated "forbidden" virtual
// method implementation.