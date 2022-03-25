#ifndef FILTER_H
#define FILTER_H

 namespace Jiabh {
     /**
     * @brief SQL过滤条件
     */
    class Filter
    {
    public:
        Filter();

        Filter operator&&(const Filter &other);
        Filter operator||(const Filter &other);
        Filter operator!();
    };
}

#endif // FILTER_H
