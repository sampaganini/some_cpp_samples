#ifndef map_template_h
#define map_template_h

template <typename key_temp, typename data_temp> 
class map_template
{
    private:
    struct node_temp
    {
        key_temp key;
        data_temp data;
        node_temp* next;
        
        node_temp(): next(NULL) {};
    };
    node_temp* head;
    
    public:
    map_template(): head(NULL) {}
    map_template(const map_template & another)
    {
        node_temp* first = 0;
        node_temp* second = 0;
        
        try {
            
         if(another.head == 0)
         {
             head = 0;
         } 
         
         else{
             head = new node_temp;
             head->key = another.head->key;
             head->data = another.head->data;
             first = head;
             second = another.head->next;
         }
         for(;;)
         {
             if(!second) break;
             first->next = new node_temp;
             first = first->next;
             first->key = second->key;
             first->data = second->data;
             second = second->next;
         }
         first->next = 0;
        }
        catch(...)
        {
            while(head)
            {
                node_temp* storage = head->next;
                delete head;
                head = storage;
            };
            throw;
        };
    }
    
    map_template & operator = (const map_template & an)
    {
        if(this == &an)
        {
            return *this;
        }
        
        map_template tem (an); 
        
        node_temp* helper = head;
        head = tem.head;
        tem.head = helper;
        return *this;
        
    }
    
    ~map_template()
    {
        for(;;)
        {
            if(!head) break;
            node_temp* help = head;
            head = head->next;
            delete help;
        }
        
        
    }
    
    
    void Add(key_temp new_key, data_temp new_data)
    {
        node_temp* nef = new node_temp;
        try{
            nef->key = new_key;
            nef->data = new_data;
        }
        catch(...)
        {
            delete nef;
            throw;
        };
        nef->next = head;
        head = nef;
    }
    
    
    
    data_temp* Find(key_temp finder)
    {
        node_temp*i = head;
        for(i = head; i!= NULL; i = i->next)
        {
            if(i->key == finder)
            {
                return &i->data;
            }
        }
        
        return 0;
    }
    
    
    friend std::ostream& operator <<(std::ostream& os,const map_template& mmp)
    {
        node_temp*i = mmp.head;
         for(i = mmp.head; i!= NULL; i = i->next)
        {
            os << i->key << ": " <<  i->data << '\n';
            
        }
        return os;
    }
};





#endif /* map_template.h */