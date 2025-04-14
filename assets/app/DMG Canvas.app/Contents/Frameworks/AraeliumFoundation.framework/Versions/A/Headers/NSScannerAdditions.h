//
//  NSScannerAdditions.h
//  AraeliumFoundation
//
//  Created by Seth Willits on 10/8/11.
//  Copyright 2011 Araelium Group. All rights reserved.
//

#import <Cocoa/Cocoa.h>


@interface NSScanner (AraeliumPeekAdditions)

- (BOOL)peekInt:(int *)value;
- (BOOL)peekInteger:(NSInteger *)value;
- (BOOL)peekHexLongLong:(unsigned long long *)result;
- (BOOL)peekHexFloat:(float *)result;
- (BOOL)peekHexDouble:(double *)result;
- (BOOL)peekHexInt:(unsigned *)value;
- (BOOL)peekLongLong:(long long *)value;
- (BOOL)peekFloat:(float *)value;
- (BOOL)peekDouble:(double *)value;
- (BOOL)peekString:(NSString *)string intoString:(NSString **)value;
- (BOOL)peekCharactersFromSet:(NSCharacterSet *)set intoString:(NSString **)value;
- (BOOL)peekUpToString:(NSString *)string intoString:(NSString **)value;
- (BOOL)peekUpToCharactersFromSet:(NSCharacterSet *)set intoString:(NSString **)value;


- (BOOL)scanStringOfLength:(NSUInteger)length intoString:(NSString **)value;
- (BOOL)peekStringOfLength:(NSUInteger)length intoString:(NSString **)value;


@end
