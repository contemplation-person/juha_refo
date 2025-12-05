import numbers

def NULL_not_found(object: any)-> int:
    if object is None :
        print("Nothing :", object, type(object))
    elif object == 0 and isinstance(object, int) :
        print("Zero :", object, type(object))
    elif isinstance(object, numbers.Number):
        print("Cheese :", object, type(object))
    elif object == "" :
        print("Empty :", object, type(object))
    elif object is False :
        print("Fake :", object, type(object))
    else :
        print("Type not found")

    return 1 

 #your code here
